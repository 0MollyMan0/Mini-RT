/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:23:57 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/25 13:54:49 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	obj_add_back(t_object **obj, t_object *new)
{
	t_object	*last;

	if (!obj || !new)
		return ;
	if (!*obj)
	{
		*obj = new;
		return ;
	}
	last = *obj;
	while (last->next)
		last = last->next;
	last->next = new;
}
