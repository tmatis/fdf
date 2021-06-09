/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:07:28 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/09 22:49:20 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

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
	mlx_put_image_to_window(info.mlx, info.win, info.frame.img, 0, 0);
	return (0);
}

void	graphic(void)
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
	mlx_loop_hook(info.mlx, render, &info);
	mlx_loop(info.mlx);
}

int	main(int argc, char **argv)
{
	int		map_file;

	if (argc == 2)
	{
		map_file = load_file(argv[1]);
		close(map_file);
		graphic();
	}
	else
	{
		ft_puterror("fdf", "main", "usage is ./fdf path/to/map.fdf");
		return (2);
	}
}