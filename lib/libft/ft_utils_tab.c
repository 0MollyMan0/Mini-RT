/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:07:13 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/24 10:29:27 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	str_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**dup_str_tab(char **tab)
{
	char	**new_tab;
	int		i;

	new_tab = malloc(sizeof(char *) * (str_tab_len(tab) + 1));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (!new_tab[i])
		{
			clean_tab(tab, i);
			return (NULL);
		}
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

void	clean_tab(char **tab, int i)
{
	while (i > 0)
		free(tab[--i]);
	free(tab);
}
