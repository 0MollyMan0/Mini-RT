/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/19 09:06:49 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_hit	hit_cylinder(t_ray ray, t_cy *cylinder)
{
	t_hit	hit;

	(void)cylinder;
	(void)ray;
	hit.dst = -1;
	hit.col_obj = init_color(0, 0, 0);
	return (hit);
}
