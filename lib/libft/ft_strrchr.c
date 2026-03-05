/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:25:49 by anfouger          #+#    #+#             */
/*   Updated: 2025/10/27 14:47:18 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			res = (char *)s + i;
		}
		i++;
	}
	if (res)
	{
		return (res);
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
