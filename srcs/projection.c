/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:02:08 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 20:02:39 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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