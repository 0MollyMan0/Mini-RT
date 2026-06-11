/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/11 15:34:56 by anfouger         ###   ########.fr       */
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
		hit.is_hit = 0;
	else
		hit.is_hit = 1;
	return (hit);
}

static t_hit	is_hit_top_disk(t_ray ray, t_cy *cylinder)
{
	t_hit	hit;
	t_vec3	top_center;
	t_vec3	p;
	
	top_center = vec_add(cylinder->pos, 
		vec_mult(cylinder->n_vec, cylinder->height * 0.5));
	hit.dst = calc_t_disk(ray, top_center, cylinder->n_vec);
	p = vec_mult(vec_add(ray.origin, ray.dir), hit.dst);
	if (vec_length(vec_sub(p, top_center)) <= cylinder->dia / 2)
	{
		hit.is_hit = 1;
		return (hit);
	}
	hit.is_hit = 0;
	return (hit);
}

static t_hit	is_hit_bottom_disk(t_ray ray, t_cy *cylinder)
{
	t_hit	hit;
	t_vec3	bottom_center;
	t_vec3	p;

	bottom_center = vec_sub(cylinder->pos,
		vec_mult(cylinder->n_vec, cylinder->height * 0.5));
	hit.dst = calc_t_disk(ray, bottom_center, vec_mult(cylinder->n_vec, -1));
	p = vec_mult(vec_add(ray.origin, ray.dir), hit.dst);
	if (vec_length(vec_sub(p, bottom_center)) <= cylinder->dia / 2)
	{
		hit.is_hit = 1;
		return (hit);
	}
	hit.is_hit = 0;
	return (hit);
}

t_hit	hit_cylinder(t_ray ray, t_cy *cylinder)
{
	t_hit	hit_cy;
	t_hit	hit_top_disk;
	t_hit	hit_bottom_disk;
	t_vec3	q;
	double	height;

	hit_cy = is_hit_cylinder(ray, cylinder);
	hit_bottom_disk = is_hit_bottom_disk(ray, cylinder);
	hit_top_disk = is_hit_top_disk(ray, cylinder);
	if (hit_cy.is_hit)
	{
		hit_cy.col_obj = cylinder->color;
		height = vec_dot(vec_sub(hit_cy.point, cylinder->pos), cylinder->n_vec);
		q = vec_add(cylinder->pos, vec_mult(cylinder->n_vec, height));
		hit_cy.normal = vec_normalize(vec_sub(hit_cy.point, q));
		return (hit_cy);
	}
	if (hit.is_hit)
	{
		
	}
	hit.dst = -1;
	return (hit);
}
