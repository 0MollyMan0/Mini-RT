/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:55:24 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/28 06:46:52 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	verif_rgb_syntax(char *str)
{
	char	**sub_tab;
	int		i;
	int		j;

	sub_tab = ft_split(str, ',');
	i = 0;
	if (!str || !sub_tab ||str_tab_len(sub_tab) > 3)
		return (0);
	while (sub_tab[i])
	{
		j = 0;
		while (sub_tab[i][j])
		{
			if (!ft_isdigit(sub_tab[i][j]))
			{
				free_str_tab(sub_tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_str_tab(sub_tab);
	return (1);
}

int	verif_vec_syntax(char *str)
{
	char	**tab;
	int		i;

	tab = ft_split(str, ',');
	i = 0;
	if (str_tab_len(tab) != 3)
	{
		free_str_tab(tab);
		return (0);
	}
	while (tab[i])
	{
		if (!is_valid_double(tab[i]))
		{
			free_str_tab(tab);
			return (0);
		}
		i++;
	}
	free_str_tab(tab);
	return (1);
}
