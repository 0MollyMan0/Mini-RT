/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:48:00 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/06 09:54:00 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static double calc_dst(t_ray ray, t_pl *plane)
{
	double a;
	double b;
	double dst;

	a = vec_dot(vec_sub(ray.origin, plane->pos), plane->n_vec);
	b = vec_dot(ray.dir, plane->n_vec);
	if (b == 0)
		return (0);
	dst = -a/b;
	return (dst);
}

t_hit	hit_plane(t_ray ray, t_pl *plane)
{
	t_hit	hit;

	hit.dst = calc_dst(ray, plane);
	if (hit.dst <= 0) 
	{
		hit.is_hit = 0;
		return (hit);
	}
	hit.col_obj = plane->color;
	hit.point = vec_add(ray.origin, vec_mult(ray.dir, hit.dst));
	hit.normal = plane->n_vec;
	hit.is_hit = 1;
	return (hit);
}
