/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:24:30 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 17:55:11 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define KEY_CHAR_X 13
#define KEY_CHAR_Y 20

void		draw_key_frame(int x, int y, t_frame frame)
{
	t_dot	start;
	t_dot	end;

	start.x = x;
	start.y = y;
	end.x = x + 30;
	end.y = y + 30;
	draw_square(start, end, 0xababab, frame);
	start.x = x + 5;
	start.y = y + 5;
	end.x = x + 30 - 5;
	end.y = y + 30 - 5;
	draw_square(start, end, 0x212121, frame);
}

void	draw_key_text(int x, int y, char *key, t_info info)
{
	mlx_string_put(info.mlx, info.win,
		x + KEY_CHAR_X, y + KEY_CHAR_Y, 0xFFFFFF, key);
}

void	put_text_center(char *str, int y, int color, t_info info)
{
	int		x;

	x = (200 / 2) - (ft_strlen(str) * 6) / 2;
	mlx_string_put(info.mlx, info.win, x, y, color, str);
}

t_frame		get_menu_frame(t_info info)
{
	t_frame menu_frame;
	t_dot	start;
	t_dot	end;

	start.x = 0;
	start.y = 0;
	end.x = 200;
	end.y = 700;
	menu_frame = frame_init(info.mlx, 200, 700);
	draw_square(start, end, 0x333333, menu_frame);
	draw_key_frame(85, 90, menu_frame);
	draw_key_frame(45, 130, menu_frame);
	draw_key_frame(85, 130, menu_frame);
	draw_key_frame(125, 130, menu_frame);
	draw_key_frame(85, 200, menu_frame);
	draw_key_frame(45, 240, menu_frame);
	draw_key_frame(85, 240, menu_frame);
	draw_key_frame(125, 240, menu_frame);
	return (menu_frame);
}

void	put_menu_text(t_info info)
{
	put_text_center("tmatis's FdF", 20, 0xFFFFFF, info);
	put_text_center("HELP MENU", 40, 0xFFFFFF, info);
	put_text_center("Translate map", 70, 0xFFFFFF, info);
	draw_key_text(85, 90, "W", info);
	draw_key_text(45, 130, "A", info);
	draw_key_text(85, 130, "S", info);
	draw_key_text(125, 130, "S", info);
	draw_key_text(85, 200, "^", info);
	draw_key_text(45, 240, "<", info);
	draw_key_text(85, 240, "v", info);
	draw_key_text(125, 240, ">", info);
	put_text_center("Rotate", 185, 0xFFFFFF, info);

}