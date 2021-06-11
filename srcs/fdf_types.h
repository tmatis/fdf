/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:53:04 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 12:36:45 by tmatis           ###   ########.fr       */
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
	double	gamma;
	double	alpha;
	double	beta;
	double	offset_x;
	double	offset_y;
	double	coef_z;
	int		plus_key;
	int		minus_key;
	int		q_key;
	int		e_key;
	int		w_key;
	int		a_key;
	int		s_key;
	int		d_key;
	int		up_arrow_key;
	int		down_arrow_key;
	int		left_arrow_key;
	int		right_arrow_key;
	int		c_key;
	int		v_key;
}	t_info;

#endif