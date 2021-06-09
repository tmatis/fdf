/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:41:13 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/09 13:54:20 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic_utils.h"

t_frame			frame_init(void *mlx, int x, int y)
{
	t_frame	frame;

	frame.img = mlx_new_image(mlx, x, y);
	if (!frame.img)
	{
		ft_puterror("fdf", "frame_init", strerror(errno));
		exit (127);
	}
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel,
			&frame.line_length, &frame.endian);
	if (!frame.addr)
	{
		ft_puterror("fdf", "frame_init", strerror(errno));
		exit (127);
	}
	return (frame);
}

/*
** Put pixel on frame at x y with of color
*/
void			frame_put_pixel(t_frame f, int x, int y, int color)
{
	char	*dst;

	dst = f.addr + (y * f.line_length + x * (f.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
** return: color of the pixel of frame at x, y
*/
unsigned	int	frame_get_pixel(t_frame f, int x, int y)
{
	char	*dst;

	dst = f.addr + (y * f.line_length + x * (f.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}