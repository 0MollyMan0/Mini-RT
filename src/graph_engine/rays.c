/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:49:13 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/19 09:05:23 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3	calc_up(t_vec3 forward, t_vec3 right)
{
	return (vec_normalize(vec_cross(right, forward)));
}

t_vec3	calc_right(t_vec3 forward, t_vec3 up)
{
	return (vec_normalize(vec_cross(forward, up)));
}

t_ray	calc_ray(t_vec3 origin, t_vec3	goal)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = vec_normalize(vec_sub(goal, origin));
	return (ray);
}

t_ray	calc_ray_cam(double sx, double sy, t_data *data)
{
	t_ray	ray;

	ray.origin = data->scene.cam.pos;
	data->scene.cam.forward = vec_normalize(data->scene.cam.n_orientation);
	data->scene.cam.up = init_vec(0, 1, 0);
	data->scene.cam.right = calc_right(data->scene.cam.forward,
			data->scene.cam.up);
	data->scene.cam.up = calc_up(data->scene.cam.forward,
			data->scene.cam.right);
	ray.dir = vec_normalize(vec_add(data->scene.cam.forward, vec_add(vec_mult
					(data->scene.cam.right, sx),
					vec_mult(data->scene.cam.up, sy))));
	return (ray);
}
