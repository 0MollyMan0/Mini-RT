/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:59:37 by anfouger          #+#    #+#             */
/*   Updated: 2025/10/26 14:47:42 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;

	if (nmemb != 0 && nmemb * size / nmemb != size)
		return (NULL);
	if (!nmemb || !size)
		return (malloc(0));
	res = malloc (nmemb * size);
	if (res != NULL)
		ft_memset(res, 0, nmemb * size);
	return (res);
}
