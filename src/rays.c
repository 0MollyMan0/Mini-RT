/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:49:13 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/17 10:50:21 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ray	calc_ray(double sx, double sy, t_data *data)
{
	t_ray	ray;
	double	len;
	t_vec3	point;

	ray.origin = data->cam;
	point.x = data->cam.x + sx;
	point.y = data->cam.y + sy;
	point.z = data->cam.z - 1.0;
	ray.dir.x = point.x - data->cam.x;
	ray.dir.y = point.y - data->cam.y;
	ray.dir.z = point.z - data->cam.z;
	len = sqrt(ray.dir.x*ray.dir.x + ray.dir.y*ray.dir.y
		+ ray.dir.z*ray.dir.z);
	ray.dir.x /= len;
	ray.dir.y /= len;
	ray.dir.z /= len;
	return (ray);
}
