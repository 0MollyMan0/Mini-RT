/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 07:54:26 by anfouger          #+#    #+#             */
/*   Updated: 2025/10/26 14:50:56 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stdlib.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	x;

	if (little[0] != '\0')
	{
		i = 0;
		while (big[i] && i < size)
		{
			j = 0;
			x = i;
			while (big[x] == little[j] && x < size)
			{
				if (little[j + 1] == '\0')
					return ((char *)&big[i]);
				x++;
				j++;
			}
			i++;
		}
		return (NULL);
	}
	else
		return ((char *)big);
}
