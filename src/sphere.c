/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:53:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/18 13:50:21 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_sphere	init_sphere(void)
{
	t_sphere	sphere;

	sphere.c.x = 0;
	sphere.c.y = 0;
	sphere.c.z = -3;
	sphere.r = 0.5;
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

	delta = calc_delta(calc_b(ray, sphere), calc_c(ray, sphere));
	if (delta >= 0)
		return (1);
	return (0);
}
