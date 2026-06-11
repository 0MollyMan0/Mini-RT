/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:31:41 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/11 10:32:09 by anfouger         ###   ########.fr       */
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