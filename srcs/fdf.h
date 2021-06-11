/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:42:31 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 20:08:18 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <errno.h>
# include "../minilibx/mlx.h" 
# include "../libft/libft.h"
# include "fdf_types.h"
# include "graphic_utils/graphic_utils.h"

t_map	parse_map(int map_fd);
int		event_key(unsigned int key, t_info *info);
int		event_key_release(unsigned int key, t_info *info);
void	iso_projection(t_info *info);
void	front_projection(t_info *info);
void	flat_projection(t_info *info);
void	iso_projection(t_info *info);
t_frame	get_menu_frame(t_info info);
void	put_menu_text(t_info info);
int		exit_free(t_info *info);
t_dot	compute_position(t_dot dot, t_info info);
void	key_handle(t_info *info);

#endif