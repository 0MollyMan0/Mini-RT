/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 09:48:57 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/19 09:08:29 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	vec_dot(t_vec3 a, t_vec3 b)
{
	return (
		a.x * b.x
		+ a.y * b.y
		+ a.z * b.z
	);
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	});
}

double	vec_distance(t_vec3 a, t_vec3 b)
{
	return (vec_length(vec_sub(b, a)));
}

t_vec3	vec_negate(t_vec3 vec)
{
	t_vec3	result;

	result.x = vec.x * -1;
	result.y = vec.y * -1;
	result.z = vec.z * -1;
	return (result);
}

t_vec3	vec_clamp(t_vec3 vec, double min, double max)
{
	t_vec3	result;

	if (vec.x < min)
		result.x = min;
	else if (vec.x > max)
		result.x = max;
	else
		result.x = vec.x;
	if (vec.y < min)
		result.y = min;
	else if (vec.y > max)
		result.y = max;
	else
		result.y = vec.y;
	if (vec.z < min)
		result.z = min;
	else if (vec.z > max)
		result.z = max;
	else
		result.z = vec.z;
	return (result);
}
