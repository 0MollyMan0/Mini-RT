/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:43:24 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/08 14:24:01 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_vec3	rotate_vec(t_vec3 v, t_vec3 axis, double angle)
{
	t_vec3	part1;
	t_vec3	part2;
	t_vec3	part3;

	axis = vec_normalize(axis);
	part1 = vec_mult(v, cos(angle));
	part2 = vec_mult(vec_cross(axis, v), sin(angle));
	part3 = vec_mult(axis, vec_dot(axis, v) * (1.0 - cos(angle)));
	return (vec_add(vec_add(part1, part2), part3));
}

void	rotate_camera_yaw(t_cam *cam, double angle)
{
	cam->forward = rotate_vec(cam->forward, cam->up, angle);
	cam->right   = rotate_vec(cam->right,   cam->up, angle);
	cam->forward = vec_normalize(cam->forward);
	cam->right   = vec_normalize(cam->right);
	cam->up      = vec_normalize(cam->up);
}

void	rotate_camera_pitch(t_cam *cam, double angle)
{
	cam->forward = rotate_vec(cam->forward, cam->right, angle);
	cam->up      = rotate_vec(cam->up,      cam->right, angle);
	cam->forward = vec_normalize(cam->forward);
	cam->right   = vec_normalize(cam->right);
	cam->up      = vec_normalize(cam->up);
}
