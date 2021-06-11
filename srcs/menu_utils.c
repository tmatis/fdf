/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:31:03 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 20:35:23 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_key_frame(int x, int y, t_frame frame)
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
		x + 13, y + 20, 0xFFFFFF, key);
}

void	put_text_center(char *str, int y, int color, t_info info)
{
	int		x;

	x = (200 / 2) - (ft_strlen(str) * 6) / 2;
	mlx_string_put(info.mlx, info.win, x, y, color, str);
}
