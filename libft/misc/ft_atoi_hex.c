/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:19:22 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/11 21:37:51 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"

#include "../char/char.h"

static int	base_index(char c)
{
	char	*base_up;
	char	*base_down;
	int		i;

	base_up = "0123456789abcdef";
	base_down = "0123456789ABCDEF";
	i = 0;
	while (base_up[i])
	{
		if (c == base_up[i] || c == base_down[i])
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	ft_atoi_hex(const char *str)
{
	int unsigned	n;

	n = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	while (*str && base_index(*str) != -1)
		n = n * 16 + base_index(*str++);
	return (n);
}
