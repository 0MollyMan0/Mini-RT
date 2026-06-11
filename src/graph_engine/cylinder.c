/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/11 10:23:57 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static double	calc_delta(double a, double b, t_ray ray, t_cy *cy)
{
	double	c;
	t_vec3	m;
	double	r;

	r = cy->dia * 0.5;
	m = vec_sub(ray.origin, cy->pos);
	c = vec_dot(m, m) - pow(vec_dot(m, cy->n_vec), 2) - r * r;
	return (b * b - 4 * a * c);
}

static double	calc_b(t_ray ray, t_cy *cy)
{
	t_vec3	m;
	double	b;

	m = vec_sub(ray.origin, cy->pos);
	b = 2 * ((vec_dot(m, ray.dir)) -
		vec_dot(m, cy->n_vec) * vec_dot(ray.dir, cy->n_vec)); 
	return (b);
}

static double	calc_a(t_ray ray, t_cy *cy)
{
	double	a;

	a = vec_dot(ray.dir, ray.dir) - pow(vec_dot(ray.dir, cy->n_vec), 2);
	return (a);
}

static double	is_hit_cylinder(t_ray ray, t_cy *cylinder)
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

t_hit	hit_cylinder(t_ray ray, t_cy *cylinder)
{
	t_hit	hit;
	double	height_pos;

	hit.dst = is_hit_cylinder(ray, cylinder);
	if (hit.dst <= 0.001)
	{
		hit.is_hit = 0;
		return (hit);
	}
	hit.point = vec_add(ray.origin, vec_mult(ray.dir, hit.dst));
	height_pos = vec_dot(vec_sub(hit.point, cylinder->pos), cylinder->n_vec);
	if (height_pos < -cylinder->height/2 || height_pos > cylinder->height/2)
	{
		hit.is_hit = 0;
		return (hit);
	}
	hit.col_obj = cylinder->color;
	hit.is_hit = 1;
	return (hit);
}
