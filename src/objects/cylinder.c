/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/23 17:58:20 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_hit	is_hit_side(t_ray ray, t_cy *cy)
{
	t_hit	hit;
	double	p_height;

	hit.dst = calc_t_cy(ray, cy);
	if (hit.dst <= 0.001)
	{
		hit.is_hit = 0;
		hit.dst = -1;
		return (hit);
	}
	hit.point = vec_add(ray.origin, vec_mult(ray.dir, hit.dst));
	p_height = vec_dot(vec_sub(hit.point, cy->pos), cy->n_vec);
	if (p_height < -cy->height / 2 || p_height > cy->height / 2)
		hit.is_hit = 0;
	else
	{
		hit.normal = vec_normalize(vec_sub(hit.point,
					vec_add(cy->pos, vec_mult(cy->n_vec, vec_dot(
								vec_sub(hit.point, cy->pos), cy->n_vec)))));
		hit.col_obj = cy->color;
		hit.is_hit = 1;
	}
	return (hit);
}

static t_hit	is_hit_top(t_ray ray, t_cy *cy)
{
	t_hit	hit;
	t_vec3	top_center;

	top_center = vec_add(cy->pos,
			vec_mult(cy->n_vec, cy->height * 0.5));
	hit.dst = calc_t_disk(ray, top_center, cy->n_vec);
	if (hit.dst <= 0.001)
	{
		hit.is_hit = 0;
		hit.dst = -1;
		return (hit);
	}
	hit.point = vec_add(ray.origin, vec_mult(ray.dir, hit.dst));
	if (vec_length(vec_sub(hit.point, top_center)) <= cy->dia / 2)
	{
		hit.is_hit = 1;
		hit.normal = cy->n_vec;
		hit.col_obj = cy->color;
		return (hit);
	}
	hit.dst = -1;
	hit.is_hit = 0;
	return (hit);
}

static t_hit	is_hit_bottom(t_ray ray, t_cy *cy)
{
	t_hit	hit;
	t_vec3	bottom_center;

	bottom_center = vec_sub(cy->pos,
			vec_mult(cy->n_vec, cy->height * 0.5));
	hit.dst = calc_t_disk(ray, bottom_center, vec_mult(cy->n_vec, -1));
	if (hit.dst <= 0.001)
	{
		hit.is_hit = 0;
		hit.dst = -1;
		return (hit);
	}
	hit.point = vec_add(ray.origin, vec_mult(ray.dir, hit.dst));
	if (vec_length(vec_sub(hit.point, bottom_center)) <= cy->dia / 2)
	{
		hit.is_hit = 1;
		hit.normal = vec_mult(cy->n_vec, -1);
		hit.col_obj = cy->color;
		return (hit);
	}
	hit.dst = -1;
	hit.is_hit = 0;
	return (hit);
}

t_hit	closest_hit(t_hit hit_side, t_hit hit_bottom, t_hit hit_top)
{
	t_hit	hit;

	hit.dst = -1;
	hit.is_hit = 0;
	if (hit_side.is_hit)
		hit = hit_side;
	if (hit_top.is_hit
		&& (!hit.is_hit || hit_top.dst < hit.dst))
		hit = hit_top;
	if (hit_bottom.is_hit
		&& (!hit.is_hit || hit_bottom.dst < hit.dst))
		hit = hit_bottom;
	return (hit);
}

t_hit	hit_cylinder(t_ray ray, t_cy *cy)
{
	t_hit	hit_side;
	t_hit	hit_top;
	t_hit	hit_bottom;
	t_hit	hit;

	cy->n_vec = vec_normalize(cy->n_vec);
	hit_side = is_hit_side(ray, cy);
	hit_bottom = is_hit_bottom(ray, cy);
	hit_top = is_hit_top(ray, cy);
	hit = closest_hit(hit_side, hit_bottom, hit_top);
	if (hit.is_hit)
		return (hit);
	hit.dst = -1;
	return (hit);
}
