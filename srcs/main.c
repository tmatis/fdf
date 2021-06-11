/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:07:28 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 14:15:12 by tmatis           ###   ########.fr       */
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

t_dot	compute_center(t_dot dot, t_info info)
{
	int	offset_x;
	int	offset_y;

	offset_x = info.frame.x / 2 + info.offset_x;
	offset_y = info.frame.y / 2 + info.offset_y;
	dot.x += offset_x;
	dot.y += offset_y;
	return (dot);
}

t_dot	compute_position(t_dot dot, t_info info)
{
	dot.x = dot.x * info.zoom - (info.map.x * info.zoom) / 2;
	dot.y = dot.y * info.zoom - (info.map.y * info.zoom) / 2;
	dot.z *= info.zoom * info.coef_z;
	dot = transform_x(dot, info.alpha);
	dot = transform_y(dot, info.beta);
	dot = transform_z(dot, info.gamma);
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
	int	selected_zoom;

	zoom_value_x = frame.x / map.x / 2;
	zoom_value_y = frame.y / map.y / 2;
	if (zoom_value_y > zoom_value_x)
		 selected_zoom = zoom_value_x;
	else
		selected_zoom = zoom_value_y;
	if (selected_zoom < 2)
		return (2);
	return (selected_zoom);
}

void	key_handle(t_info *info)
{
	if (info->plus_key && (info->zoom + info->zoom/50) < 250)
		info->zoom += info->zoom / 50;
	if (info->minus_key && (info->zoom - info->zoom/50) > 2)
		info->zoom -= info->zoom / 50;
	if (info->e_key)
		info->gamma += 0.02;
	if (info->q_key)
		info->gamma -= 0.02;
	if (info->w_key)
		info->offset_y += 1.8;
	if (info->s_key)
		info->offset_y -= 1.8;
	if (info->a_key)
		info->offset_x += 1.8;
	if (info->d_key)
		info->offset_x -= 1.8;
	if (info->up_arrow_key)
		info->alpha += 0.02;
	if (info->down_arrow_key)
		info->alpha -= 0.02;
	if (info->left_arrow_key)
		info->beta += 0.02;
	if (info->right_arrow_key)
		info->beta -= 0.02;
	if (info->c_key && (info->coef_z - 0.1) >= 0)
		info->coef_z -= 0.01;
	if (info->v_key)
		info->coef_z += 0.01;
}

int	render(t_info *info)
{
	t_dot	start;
	t_dot	end;

	start.x = 0;
	start.y = 0;
	end.x = info->frame.x;
	end.y = info->frame.y;
	key_handle(info);
	draw_square(start, end, 0x0, info->frame);
	render_lines(*info);
	mlx_put_image_to_window(info->mlx, info->win, info->frame.img, 0, 0);
	return (0);
}

void	init_values(t_info *info)
{
	info->plus_key = 0;
	info->minus_key = 0;
	info->q_key = 0;
	info->e_key = 0;
	info->w_key = 0;
	info->s_key = 0;
	info->a_key = 0;
	info->d_key = 0;
	info->c_key = 0;
	info->v_key = 0;
	info->down_arrow_key = 0;
	info->up_arrow_key = 0;
	info->left_arrow_key = 0;
	info->right_arrow_key = 0;
	info->offset_x = 0;
	info->offset_y = 0;
	info->gamma = 0;
	info->alpha = 0;
	info->beta = 0;
	info->coef_z = 0.25;
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
	info.win = mlx_new_window(info.mlx, 1200, 700, "FdF");
	if (!info.win)
	{
		ft_puterror("fdf", "mlx_new_window", strerror(errno));
		mlx_destroy_display(info.mlx);
		free(info.mlx);
		exit(1);
	}
	info.frame = frame_init(info.mlx, 1200, 700);
	info.map = map;
	info.zoom = compute_zoom(info.map, info.frame);
	init_values(&info);
	mlx_hook(info.win, 2, 1L, event_key, &info);
	mlx_hook(info.win, 3, 1L << 1, event_key_release, &info);
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