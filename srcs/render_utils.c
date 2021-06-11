/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:48:20 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 21:55:31 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	choose_color(t_dot a, t_dot b)
{
	if (a.color != 0xFFFFFF)
		return (a.color);
	else
		return (b.color);
}
