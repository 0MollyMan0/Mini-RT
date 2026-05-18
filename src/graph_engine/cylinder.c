/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/18 09:40:29 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_hit hit_cylinder(t_ray ray, t_cy *cylinder)
{
	(void)cylinder;
	(void)ray;
	t_hit	hit;

	hit.dst = -1;
	hit.col_obj = init_color(0,0,0);
	return (hit);
}
