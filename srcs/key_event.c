/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:28:34 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 20:29:24 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	event_key_2(unsigned int key, t_info *info)
{
	if (key == 0xff53)
		info->right_arrow_key = 1;
	else if (key == 0x63)
		info->c_key = 1;
	else if (key == 0x76)
		info->v_key = 1;
	else if (key == 0x66)
		front_projection(info);
	else if (key == 0x69)
		iso_projection(info);
	else if (key == 0x70)
		flat_projection(info);
	else if (key == 0x68)
	{
		info->menu_toggle = !info->menu_toggle;
		if (info->menu_toggle)
			info->render_menu = 1;
	}
	else if (key == 0xff1b)
		exit_free(info);
}

int	event_key(unsigned int key, t_info *info)
{
	if (key == 0xffab)
		info->plus_key = 1;
	else if (key == 0xffad)
		info->minus_key = 1;
	else if (key == 0x71)
		info->q_key = 1;
	else if (key == 0x65)
		info->e_key = 1;
	else if (key == 0x77)
		info->w_key = 1;
	else if (key == 0x73)
		info->s_key = 1;
	else if (key == 0x61)
		info->a_key = 1;
	else if (key == 0x64)
		info->d_key = 1;
	else if (key == 0xff52)
		info->up_arrow_key = 1;
	else if (key == 0xff54)
		info->down_arrow_key = 1;
	else if (key == 0xff51)
		info->left_arrow_key = 1;
	else
		event_key_2(key, info);
	return (0);
}

void	event_key_release_2(unsigned int key, t_info *info)
{
	if (key == 0x64)
		info->d_key = 0;
	else if (key == 0xff52)
		info->up_arrow_key = 0;
	else if (key == 0xff54)
		info->down_arrow_key = 0;
	else if (key == 0xff51)
		info->left_arrow_key = 0;
	else if (key == 0xff53)
		info->right_arrow_key = 0;
	else if (key == 0x63)
		info->c_key = 0;
	else if (key == 0x76)
		info->v_key = 0;
}

int	event_key_release(unsigned int key, t_info *info)
{
	if (key == 0xffab)
		info->plus_key = 0;
	else if (key == 0xffad)
		info->minus_key = 0;
	else if (key == 0x71)
		info->q_key = 0;
	else if (key == 0x65)
		info->e_key = 0;
	else if (key == 0x77)
		info->w_key = 0;
	else if (key == 0x73)
		info->s_key = 0;
	else if (key == 0x61)
		info->a_key = 0;
	else
		event_key_release_2(key, info);
	return (0);
}
