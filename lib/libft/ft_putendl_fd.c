/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 08:44:23 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/08 12:10:50 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (!s || fd < 0)
		return ;
	len = ft_strlen(s);
	write (fd, s, len);
	write (fd, "\n", 1);
}
