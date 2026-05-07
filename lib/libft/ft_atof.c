/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:56:46 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/07 11:59:38 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	prepare(char *str, int *sign, double *res, int *div)
{
	int	i;

	i = 0;
	*sign = 1;
	*div = 10;
	*res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *str)
{
	int		i;
	double	res;
	int		sign;
	int		div;

	i = prepare(str, &sign, &res, &div);
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	if (str[i] != '.' || !str[i + 1] || !ft_isdigit(str[i + 1]))
		return (res * sign);
	i++;
	while (ft_isdigit(str[i]))
	{
		res += (double)(str[i] - 48) / (double)div;
		div *= 10;
		i++;
	}
	return (res * sign);
}
