/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:15:34 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 20:47:24 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic_utils.h"

void	draw_square(t_dot start, t_dot end, int color, t_frame frame)
{
	int	y;
	int	x;

	y = start.y;
	while (y < end.y)
	{
		x = start.x;
		while (x < end.x)
		{
			frame_put_pixel(frame, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_line(t_dot start, t_dot end, int color, t_frame frame)
{
	double	step_x;
	double	step_y;
	double	max_step;

	step_x = end.x - start.x;
	step_y = end.y - start.y;
	max_step = max(ft_fabs(step_x), ft_fabs(step_y));
	step_x /= max_step;
	step_y /= max_step;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		frame_put_pixel(frame, start.x, start.y, color);
		start.x += step_x;
		start.y += step_y;
		if (start.x > frame.x + 100 || start.y > frame.y + 100
			|| start.y < -100 || start.x < -100)
			break ;
	}
}
