/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:14:46 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/07 13:52:08 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*new;

	if (!str || !str[0] || n <= 0)
		return (NULL);
	i = 0;
	new = malloc(n + 1);
	while (i < n)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);	
}
