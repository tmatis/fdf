/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:11:25 by tmatis            #+#    #+#             */
/*   Updated: 2021/11/02 14:46:58 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	info->render_menu = 1;
	info->menu_toggle = 1;
	info->zoom = compute_zoom(info->map, info->frame);
	iso_projection(info);
	info->coef_z = 0.25;
}

void	render_lines(t_info inf)
{
	t_dot	*raw;
	int		i;

	while (inf.map.data)
	{
		raw = inf.map.data->content;
		i = 0;
		while (!raw[i].end)
		{
			if (!raw[i + 1].end)
				draw_line(compute_position(raw[i], inf),
					compute_position(raw[i + 1], inf),
					choose_color(raw[i], raw[i + 1]), inf.frame);
			if (inf.map.data->next)
				draw_line(compute_position(raw[i], inf),
					compute_position(((t_dot *)inf.map.data->next->content)[i],
						inf),
					choose_color(raw[i],
						((t_dot *)inf.map.data->next->content)[i]),
					inf.frame);
			i++;
		}
		inf.map.data = inf.map.data->next;
	}
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
	if (info->render_menu && info->menu_toggle)
	{
		mlx_put_image_to_window(info->mlx, info->win,
			info->menu_frame.img, 0, 0);
		put_menu_text(*info);
		info->render_menu = 0;
	}
	render_lines(*info);
	mlx_put_image_to_window(info->mlx, info->win, info->frame.img,
		info->menu_toggle * 200, 0);
	return (0);
}

void	graphic(t_map map)
{
	t_info	info;

	info.mlx = mlx_init();
	if (!info.mlx)
	{
		ft_puterror("fdf", "mlx_init", strerror(errno));
		ft_lstclear(&map.data, ft_safe_free);
		exit(1);
	}
	info.win = mlx_new_window(info.mlx, 1200, 700, "FdF");
	if (!info.win)
	{
		ft_puterror("fdf", "mlx_new_window", strerror(errno));
		ft_lstclear(&map.data, ft_safe_free);
		mlx_destroy_display(info.mlx);
		free(info.mlx);
		exit(1);
	}
	info.frame = frame_init(info.mlx, 1200, 700);
	info.map = map;
	info.menu_frame = get_menu_frame(info);
	init_values(&info);
	mlx_hook(info.win, 33, 0, exit_free, &info);
	mlx_hook(info.win, 2, 1L, event_key, &info);
	mlx_hook(info.win, 3, 1L << 1, event_key_release, &info);
	mlx_loop_hook(info.mlx, render, &info);
	mlx_loop(info.mlx);
}
