/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:53:04 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/09 22:19:26 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPES_H

# define FDF_TYPES_H

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

typedef struct s_dot
{
	double	x;
	double	y;
	double	height;
}			t_dot;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_frame frame;
}	t_info;

#endif