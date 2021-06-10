/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:07:28 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/10 19:38:53 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>

#define H_OFFSET 300
#define V_OFFSET 100
#define ISO_ANGLE 0.523599


int	load_file(char *file)
{
	char	*find;
	int		map_file;

	find = ft_strrchr(file, '.');
	if (!find || ft_strcmp(find, ".fdf"))
	{
		ft_puterror("fdf", "load_file", "not a .fdf");
		exit(1);
	}
	map_file = open(file, O_RDONLY);
	if (map_file < 0)
	{
		ft_puterror("fdf", "load_file", strerror(errno));
		exit(1);
	}
	return (map_file);
}


/*
** dot: the dot to transform, alpha the angle in radian
*/
t_dot	transform_x(t_dot dot, double alpha)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = dot.x;
	new_y = dot.y * cos(alpha) + dot.z * sin(alpha);
	new_z = - dot.y * sin(alpha) + dot.z * cos(alpha);
	dot.x = new_x;
	dot.y = new_y;
	dot.z = new_z;
	return (dot);
}

t_dot	transform_y(t_dot dot, double beta)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = dot.x * cos(beta) + dot.z * sin(beta);
	new_y = dot.y;
	new_z = - dot.x * sin(beta) + dot.z * cos(beta);
	dot.x = new_x;
	dot.y = new_y;
	dot.z = new_z;
	return (dot);
}

t_dot	transform_z(t_dot dot, double gamma)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = dot.x * cos(gamma) - dot.y * sin(gamma);
	new_y = dot.x * sin(gamma) + dot.y * cos(gamma);
	new_z = dot.z;
	dot.x = new_x;
	dot.y = new_y;
	dot.z = new_z;
	return (dot);
}

t_dot	apply_iso(t_dot dot)
{
	double new_x;
	double new_y;

	new_x = (dot.x - dot.y) * cos(ISO_ANGLE);
	new_y = (dot.x + dot.y) * sin(ISO_ANGLE) - (dot.z * 10);
	dot.x = new_x;
	dot.y = new_y;
	return (dot);
}

t_dot	compute_center(t_dot dot, t_info info)
{
	int	offset_x;
	int	offset_y;

	offset_x = info.frame.x / 2;
	offset_y = info.frame.y / 2;
	dot.x += offset_x;
	dot.y += offset_y;
	return (dot);
}

t_dot	compute_position(t_dot dot, t_info info)
{
	dot.x = dot.x * info.zoom - (info.map.x * info.zoom) / 2;
	dot.y = dot.y * info.zoom - (info.map.y * info.zoom) / 2;
	dot = apply_iso(dot);
	//dot = transform_z(dot, 0.3);
	dot = compute_center(dot, info);
	return (dot);
}

void	render_lines(t_info info)
{
	t_dot	*raw;
	int		i;

	while (info.map.data)
	{
		raw = info.map.data->content;
		i = 0;
		while (!raw[i].end)
		{
			if (!raw[i + 1].end)
				draw_line(compute_position(raw[i], info),
					compute_position(raw[i + 1], info), raw[i + 1].color, info.frame);
			if (info.map.data->next)
				draw_line(compute_position(raw[i], info),
					compute_position(((t_dot *)info.map.data->next->content)[i], info),
						((t_dot *)info.map.data->next->content)[i].color, info.frame);
			i++;
		}
		info.map.data = info.map.data->next;
	}
}

int	compute_zoom(t_map map, t_frame frame)
{
	int	zoom_value_x;
	int	zoom_value_y;

	zoom_value_x = frame.x / map.x / 1.2;
	zoom_value_y = frame.y / map.y / 1.2;
	if (zoom_value_y > zoom_value_x)
		return (zoom_value_x);
	else
		return (zoom_value_y);
}

int	render(void *p_info)
{
	t_dot	start;
	t_dot	end;
	t_info	info;

	info = *(t_info *)p_info;
	start.x = 0;
	start.y = 0;
	end.x = 1000;
	end.y = 700;
	draw_square(start, end, 0x0, info.frame);
	render_lines(info);
	mlx_put_image_to_window(info.mlx, info.win, info.frame.img, 0, 0);
	return (0);
}

void	graphic(t_map map)
{
	t_info	info;

	info.mlx = mlx_init();
	if (!info.mlx)
	{
		ft_puterror("fdf", "mlx_init", strerror(errno));
		exit(1);
	}
	info.win = mlx_new_window(info.mlx, 1000, 700, "FdF");
	if (!info.win)
	{
		ft_puterror("fdf", "mlx_new_window", strerror(errno));
		mlx_destroy_display(info.mlx);
		free(info.mlx);
		exit(1);
	}
	info.frame = frame_init(info.mlx, 1000, 700);
	info.map = map;
	info.zoom = compute_zoom(info.map, info.frame);
	mlx_loop_hook(info.mlx, render, &info);
	mlx_loop(info.mlx);
}

int	main(int argc, char **argv)
{
	int		map_file;
	t_map	map;

	if (argc == 2)
	{
		map_file = load_file(argv[1]);
		map = parse_map(map_file);
		close(map_file);
		graphic(map);
	}
	else
	{
		ft_puterror("fdf", "main", "usage is ./fdf path/to/map.fdf");
		return (2);
	}
}