/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:57:28 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 20:28:34 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
** dot: the dot to transform, alpha the angle in radian
*/
t_dot	transform_x(t_dot dot, double alpha)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = dot.x;
	new_y = dot.y * cos(alpha) + dot.z * sin(alpha);
	new_z = -dot.y * sin(alpha) + dot.z * cos(alpha);
	dot.x = new_x;
	dot.y = new_y;
	dot.z = new_z;
	return (dot);
}

t_dot	transform_y(t_dot dot, double beta)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = dot.x * cos(beta) + dot.z * sin(beta);
	new_y = dot.y;
	new_z = -dot.x * sin(beta) + dot.z * cos(beta);
	dot.x = new_x;
	dot.y = new_y;
	dot.z = new_z;
	return (dot);
}

t_dot	transform_z(t_dot dot, double gamma)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = dot.x * cos(gamma) - dot.y * sin(gamma);
	new_y = dot.x * sin(gamma) + dot.y * cos(gamma);
	new_z = dot.z;
	dot.x = new_x;
	dot.y = new_y;
	dot.z = new_z;
	return (dot);
}

t_dot	compute_center(t_dot dot, t_info info)
{
	int	offset_x;
	int	offset_y;

	offset_x = info.frame.x / 2 + info.offset_x - (100 * info.menu_toggle);
	offset_y = info.frame.y / 2 + info.offset_y;
	dot.x += offset_x;
	dot.y += offset_y;
	return (dot);
}

t_dot	compute_position(t_dot dot, t_info info)
{
	dot.x = dot.x * info.zoom - (info.map.x * info.zoom) / 2;
	dot.y = dot.y * info.zoom - (info.map.y * info.zoom) / 2;
	dot.z *= info.zoom * info.coef_z;
	dot = transform_x(dot, info.alpha);
	dot = transform_y(dot, info.beta);
	dot = transform_z(dot, info.gamma);
	dot = compute_center(dot, info);
	return (dot);
}
