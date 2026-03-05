/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 07:54:26 by anfouger          #+#    #+#             */
/*   Updated: 2025/10/22 08:06:07 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	len_dst;
	unsigned int	len_src;
	unsigned int	i;
	unsigned int	j;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = len_dst;
	j = 0;
	if (size <= len_dst)
		return (size + len_src);
	while (src[j] && (i + 1 < size))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_dst + len_src);
}
