/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:55:24 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 14:38:17 by anfouger         ###   ########.fr       */
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
	if (str_tab_len(sub_tab) > 3)
		return (0);
	while (sub_tab[i])
	{
		j = 0;
		while (sub_tab[i][j])
		{
			if (!ft_isdigit(sub_tab[i][j]))
			{
				printf("%c", sub_tab[i][j]);
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
	int		j;

	tab = ft_split(str, ',');
	i = 0;
	if (str_tab_len(tab) > 3)
		return (0);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!(tab[i][j] == '-' && tab[i][j + 1] && ft_isdigit(tab[i][j + 1]))
			&& tab[i][j] != '.' && !ft_isdigit(tab[i][j]))
			{
				free_str_tab(tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_str_tab(tab);
	return (1);
}
