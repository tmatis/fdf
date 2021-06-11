/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:07:07 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 20:07:55 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_handle_2(t_info *info)
{
	if (info->d_key)
		info->offset_x += 1.8;
	if (info->up_arrow_key)
		info->alpha += 0.02;
	if (info->down_arrow_key)
		info->alpha -= 0.02;
	if (info->left_arrow_key)
		info->beta += 0.02;
	if (info->right_arrow_key)
		info->beta -= 0.02;
	if (info->c_key && (info->coef_z - 0.1) >= 0)
		info->coef_z -= 0.01;
	if (info->v_key)
		info->coef_z += 0.01;	
}

void	key_handle(t_info *info)
{
	if (info->plus_key && (info->zoom + info->zoom/50) < 250)
		info->zoom += info->zoom / 50;
	if (info->minus_key && (info->zoom - info->zoom/50) > 2)
		info->zoom -= info->zoom / 50;
	if (info->e_key)
		info->gamma += 0.02;
	if (info->q_key)
		info->gamma -= 0.02;
	if (info->w_key)
		info->offset_y -= 1.8;
	if (info->s_key)
		info->offset_y += 1.8;
	if (info->a_key)
		info->offset_x -= 1.8;
	key_handle_2(info);
}