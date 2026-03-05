/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:52:09 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/08 12:07:15 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	if (!*lst)
	{
		*lst = NULL;
		return ;
	}
	ptr = *lst;
	while (ptr)
	{
		del(ptr->content);
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}
