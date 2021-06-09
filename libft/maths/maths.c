/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:34:33 by tmatis            #+#    #+#             */
/*   Updated: 2021/06/09 22:16:38 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_fabs(double n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
