/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:53:04 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/10 19:38:22 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPES_H

# define FDF_TYPES_H

#include "fdf.h"

typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_frame;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_map
{
	t_list 		*data;
	double		x;
	double		y;
}			t_map;

typedef struct s_dot
{
	double	x;
	double	y;
	double	z;
	int		color;
	int		end;
}			t_dot;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_frame frame;
	t_map	map;
	double	zoom;
}	t_info;

#endif