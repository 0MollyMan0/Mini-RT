/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:22:51 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/08 12:26:32 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s2;
	unsigned int	i;

	i = 0;
	if (!s)
	{
		return ;
	}
	s2 = (unsigned char *)s;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}
