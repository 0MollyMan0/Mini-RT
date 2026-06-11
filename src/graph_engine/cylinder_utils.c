/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:31:41 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/11 13:53:07 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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

double	calc_t_cy(t_ray ray, t_cy *cylinder)
{
	double	delta;
	double	t1;
	double	t2;
	double	a;
	double	b;

	a = calc_a(ray, cylinder);
	b = calc_b(ray, cylinder);
	delta = calc_delta(a, b, ray, cylinder);
	if (delta < 0 || a < 0.001)
		return (-1);
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if (t1 > 0.001)
		return (t1);
	if (t2 > 0.001)
		return (t2);
	return (-1);
}
