/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:41:51 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/09 13:54:17 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_UTILS_H

# define GRAPHIC_UTILS_H

#include "../fdf.h"

t_frame			frame_init(void *mlx, int x, int y);
void			frame_put_pixel(t_frame f, int x, int y, int color);
unsigned	int	frame_get_pixel(t_frame f, int x, int y);

#endif