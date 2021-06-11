/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:42:31 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 21:51:08 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <errno.h>
# include "../minilibx/mlx.h" 
# include "../libft/libft.h"
# include "fdf_types.h"
# include "graphic_utils/graphic_utils.h"

t_map			parse_map(int map_fd);
int				event_key(unsigned int key, t_info *info);
int				event_key_release(unsigned int key, t_info *info);
void			iso_projection(t_info *info);
void			front_projection(t_info *info);
void			flat_projection(t_info *info);
void			iso_projection(t_info *info);
t_frame			get_menu_frame(t_info info);
void			put_menu_text(t_info info);
int				exit_free(t_info *info);
t_dot			compute_position(t_dot dot, t_info info);
void			key_handle(t_info *info);
void			graphic(t_map map);
void			draw_key_frame(int x, int y, t_frame frame);
void			draw_key_text(int x, int y, char *key, t_info info);
void			put_text_center(char *str, int y, int color, t_info info);
unsigned int	choose_color(t_dot a, t_dot b);

#endif