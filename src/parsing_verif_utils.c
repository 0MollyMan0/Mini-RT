/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 08:59:16 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 09:01:43 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	verif_rgb(char *str)
{
	char	**sub_tab;
	int		i;

	sub_tab = ft_split(str, ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_int_in_range(ft_atof(sub_tab[i]), 0, 255))
		{
			free_str_tab(sub_tab);
			return (0);	
		}
		i++;
	}
	free_str_tab(sub_tab);
	return (1);
}

int	verif_n_vec(char *str)
{
	char	**sub_tab;
	int		i;

	sub_tab = ft_split(str, ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_double_in_range(ft_atof(sub_tab[i]), 0, 1))
		{
			free_str_tab(sub_tab);
			return (0);	
		}
		i++;
	}
	free_str_tab(sub_tab);
	return (1);
}
