/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:53:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/19 10:21:04 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_sphere	init_sphere(t_vec3 center, double r, int color)
{
	t_sphere	sphere;

	sphere.c.x = center.x;
	sphere.c.y = center.y;
	sphere.c.z = center.z;
	sphere.r = r;
	sphere.color = color;
	return (sphere);
}

static double	calc_delta(double b, double c)
{
	return ((b * b) - 4 * 1 * c);
}

static double	calc_b(t_ray ray, t_sphere sphere)
{
	double	x;
	double	y;	
	double	z;

	x = (ray.origin.x - sphere.c.x) * ray.dir.x;
	y = (ray.origin.y - sphere.c.y) * ray.dir.y;
	z = (ray.origin.z - sphere.c.z) * ray.dir.z;
	return (2 * (x + y + z));
}

static double	calc_c(t_ray ray, t_sphere sphere)
{
	double	x;
	double	y;	
	double	z;

	x = (ray.origin.x - sphere.c.x) * (ray.origin.x - sphere.c.x);
	y = (ray.origin.y - sphere.c.y) * (ray.origin.y - sphere.c.y);
	z = (ray.origin.z - sphere.c.z) * (ray.origin.z - sphere.c.z);
	return (x + y + z - (sphere.r * sphere.r));
}

int	hit_sphere(t_ray ray, t_sphere sphere)
{
	double	delta;
	double	t1;
	double	t2;

	delta = calc_delta(calc_b(ray, sphere), calc_c(ray, sphere));
	if (delta < 0)
		return (-1);
	t1 = (-calc_b(ray, sphere) - sqrt(delta)) / 2.0;
	t2 = (calc_b(ray, sphere) - sqrt(delta)) / 2.0;
	if (t1 > 0.001)
		return (t1);
	if (t2 > 0.001)
		return (t2);
	return (-1);
}
