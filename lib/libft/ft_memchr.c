/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:33:25 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/08 12:08:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)s;
	if (n == 0)
	{
		return (NULL);
	}
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
		{
			return ((void *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
