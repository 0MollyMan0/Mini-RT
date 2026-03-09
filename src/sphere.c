/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:53:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 14:55:10 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_sphere	init_sphere(void)
{
	t_sphere	sphere;

	sphere.c.x = 0;
	sphere.c.y = 0;
	sphere.c.z = -5;
	sphere.r = 0.5;
	return (sphere);
}

double	calc_delta(double b, double c)
{
	return ((b * b) - 4 * 1 * c);
}

double calc_b(t_ray ray, t_sphere sphere, t_data data)
{
	double	x;
	double	y;	
	double	z;

	x = (data.cam.x - sphere.c.x) * ray.dir.x;
	y = (data.cam.y - sphere.c.y) * ray.dir.y;
	z = (data.cam.z - sphere.c.z) * ray.dir.z;
	return (2 * (x + y + z));
}

double calc_c(t_sphere sphere, t_data data)
{
	double	x;
	double	y;	
	double	z;

	x = (data.cam.x - sphere.c.x) * (data.cam.x - sphere.c.x);
	y = (data.cam.y - sphere.c.y) * (data.cam.y - sphere.c.y);
	z = (data.cam.z - sphere.c.z) * (data.cam.z - sphere.c.z);
	return (x + y + z - (sphere.r * sphere.r));
}

int	hit_sphere(t_ray ray, t_sphere sphere, t_data data)
{
	double	delta;

	delta = calc_delta(calc_b(ray, sphere, data), calc_c(sphere, data));
	if (delta >= 0)
		return (1);
	return (0);
}