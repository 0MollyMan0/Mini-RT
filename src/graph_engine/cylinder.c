/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/11 10:50:58 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	calc_t_cy(t_ray ray, t_cy *cylinder)
{
	double	delta;
	double	t1;
	double	t2;
	double	a;
	double	b;

	a = calc_a_cy(ray, cylinder);
	b = calc_b_cy(ray, cylinder);
	delta = calc_delta(a, b, ray, cylinder);
	if (delta < 0 || a == 0)
		return (-1);
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if (t1 > 0.001)
		return (t1);
	if (t2 > 0.001)
		return (t2);
	return (-1);
}

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
	if (p_height >= -cylinder->height / 2 &&
		p_height <= cylinder->height / 2)
	{
		hit.is_hit = 1;
		return (hit);
	}
	hit.is_hit = 0;
	return (hit);
}

t_hit	hit_cylinder(t_ray ray, t_cy *cylinder)
{
	t_hit	hit;

	hit = is_hit_cylinder(ray, cylinder);
	if (!hit.is_hit)
		return (hit);
	hit.col_obj = cylinder->color;
	return (hit);
}
