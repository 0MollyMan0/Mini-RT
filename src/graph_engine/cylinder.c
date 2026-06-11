/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/11 14:11:45 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_hit	is_hit_cylinder(t_ray ray, t_cy *cylinder)
{
	t_hit	hit;
	double	p_height;

	hit.dst = calc_t_cy(ray, cylinder);
	if (hit.dst <= 0.001)
	{
		hit.is_hit = 0;
		return (hit);
	}
	hit.point = vec_add(ray.origin, vec_mult(ray.dir, hit.dst));
	p_height = vec_dot(vec_sub(hit.point, cylinder->pos), cylinder->n_vec);
	if (p_height < -cylinder->height / 2 || p_height > cylinder->height / 2)
	{
		hit.is_hit = 0;
		return (hit);
	}
	hit.is_hit = 1;
	return (hit);
}

t_hit	hit_cylinder(t_ray ray, t_cy *cylinder)
{
	t_hit	hit;

	hit = is_hit_cylinder(ray, cylinder);
	if (!hit.is_hit)
	{
		hit.dst = -1;
		return (hit);	
	}
	hit.col_obj = cylinder->color;
	return (hit);
}
