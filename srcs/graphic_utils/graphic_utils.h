/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:41:51 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/09 13:23:45 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_UTILS_H

# define GRAPHIC_UTILS_H

#include "../fdf.h"

typedef	struct	s_frame
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_frame;

typedef	struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

#endif