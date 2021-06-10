/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:42:31 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/10 22:34:05 by tmatis           ###   ########.fr       */
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

#endif