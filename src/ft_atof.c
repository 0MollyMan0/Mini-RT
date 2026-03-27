/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:08:01 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/27 10:03:13 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

float	ft_atof(char *str)
{
	int		i;
	float	div;
	int		sign;
	float	res;
	
	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
    	i++;
	div = 10;
	while (ft_isdigit(str[i]))
	{
		res += (str[i] - '0') / div;
		div *= 10;
		i++;
	}
	return (res * sign);
}
