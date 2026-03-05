/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:36:46 by anfouger          #+#    #+#             */
/*   Updated: 2025/10/29 11:35:45 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	x;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		sub = ft_strdup("");
		return (sub);
	}
	if (len > slen - start)
		len = slen - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	x = 0;
	while (x < len)
	{
		sub[x] = s[start + x];
		x++;
	}
	sub[x] = '\0';
	return (sub);
}
