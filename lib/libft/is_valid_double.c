/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:38:34 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 15:24:01 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	first_part(char *str, int *i)
{
	int		count_digits;

	count_digits = 0;
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	if (!ft_isdigit(str[*i]))
		return (0);
	while (ft_isdigit(str[*i]))
	{
		count_digits++;
		(*i)++;	
	}
	if (count_digits > 20)
		return (0);
	return (1);	
}

static int	second_part(char *str, int *i)
{	
	int		count_digits;

	count_digits = 0;
	if (str[*i] != '.' || (str[*i] == '.' && !ft_isdigit(str[*i + 1])))
		return (0);
	(*i)++;
	while (ft_isdigit(str[*i]))
	{
		count_digits++;
		(*i)++;
	}
	if (str[*i] != '\0' || count_digits > 6)
		return (0);
	return (1);
}

int	is_valid_double(char *str)
{
	int		i;

	i = 0;
	if (!first_part(str, &i))
		return (0);
	if (str[i] == '\0')
		return (1);
	if (!second_part(str, &i))
		return (0);
	return (1);
}
