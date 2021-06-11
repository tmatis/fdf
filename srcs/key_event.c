/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:28:34 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 17:12:10 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dump_info(t_info info)
{
	printf("---INFO---\n");
	printf("alpha: %f\n", info.alpha);
	printf("beta: %f\n", info.beta);
	printf("gamma: %f\n", info.gamma);
	printf("zoom: %f\n", info.zoom);
	printf("coef_z: %f\n", info.coef_z);
}

void	front_projection(t_info *info)
{
	info->alpha = -0.74;
	info->beta = 0.0;
	info->gamma = 0.0;
	info->offset_x = 0;
	info->offset_y = 0;
}

void	flat_projection(t_info *info)
{
	info->alpha = 0;
	info->beta = 0;
	info->gamma = 0;
	info->offset_y = 0;
	info->offset_x = 0;
}

void	iso_projection(t_info *info)
{
	info->alpha = -0.88;
	info->beta = -0.68;
	info->gamma = 0.38;
	info->offset_x = 0;
	info->offset_y = 0;
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
	else if (key == 0xff53)
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
	else
		printf("key : %#x\n", key);	
	return (0);
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
	else if (key == 0x64)
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
	return (0);
}