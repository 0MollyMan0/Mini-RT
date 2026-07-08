/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:53:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/19 09:05:46 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static inline double	calc_delta(double b, double c)
{
	return ((b * b) - 4 * 1 * c);
}

static double	calc_b(t_ray ray, t_sp sphere)
{
	double	x;
	double	y;	
	double	z;

	x = (ray.origin.x - sphere.c.x) * ray.dir.x;
	y = (ray.origin.y - sphere.c.y) * ray.dir.y;
	z = (ray.origin.z - sphere.c.z) * ray.dir.z;
	return (2 * (x + y + z));
}

static double	calc_c(t_ray ray, t_sp sphere)
{
	double	x;
	double	y;	
	double	z;

	x = (ray.origin.x - sphere.c.x) * (ray.origin.x - sphere.c.x);
	y = (ray.origin.y - sphere.c.y) * (ray.origin.y - sphere.c.y);
	z = (ray.origin.z - sphere.c.z) * (ray.origin.z - sphere.c.z);
	return (x + y + z - ((sphere.dia / 2) * (sphere.dia / 2)));
}

double	is_hit_sphere(t_ray ray, t_sp *sphere)
{
	double	delta;
	double	t1;
	double	t2;
	double	b;
	double	c;

	b = calc_b(ray, *sphere);
	c = calc_c(ray, *sphere);
	delta = calc_delta(b, c);
	if (delta < 0)
		return (-1);
	t1 = (-b - sqrt(delta)) / 2.0;
	t2 = (-b + sqrt(delta)) / 2.0;
	if (t1 > 0.001)
		return (t1);
	if (t2 > 0.001)
		return (t2);
	return (-1);
}

t_hit	hit_sphere(t_ray ray, t_sp *sphere)
{
	t_hit	hit;

	hit.dst = is_hit_sphere(ray, sphere);
	if (hit.dst <= 0.001)
	{
		hit.is_hit = 0;
		return (hit);
	}
	hit.col_obj = sphere->color;
	hit.point = vec_add(ray.origin, vec_mult(ray.dir, hit.dst));
	hit.normal = vec_normalize(vec_sub(hit.point, sphere->c));
	hit.is_hit = 1;
	return (hit);
}
