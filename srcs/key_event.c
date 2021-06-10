/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 22:28:34 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/10 22:59:12 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return (0);
}