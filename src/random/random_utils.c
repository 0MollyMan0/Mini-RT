/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:20:07 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/13 14:58:06 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	ft_strlen_until(char *str, char c)
{
	int	i;
	
	if (!str || !str[0] || !c)
		return (-1);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	is_int_in_range(int x, int min, int max)
{
	if (x < min || x > max)
		return (0);
	return (1);
}

int	is_double_in_range(double x, double min, double max)
{
	if (x < min || x > max)
		return (0);
	return (1);
}
