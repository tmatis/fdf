/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:53:04 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/09 13:53:46 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPES_H

# define FDF_TYPES_H

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