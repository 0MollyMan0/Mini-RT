/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 09:22:27 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/13 14:26:29 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_vec3	vec_mult(t_vec3 v, double k)
{
	t_vec3	result;

	result.x = v.x * k;
	result.y = v.y * k;
	result.z = v.z * k;
	return (result);
}

double vec_length(t_vec3 v)
{
	return (sqrt(
		v.x * v.x +
		v.y * v.y +
		v.z * v.z));
}

t_vec3	vec_normalize(t_vec3 v)
{
	double	len;

	len = vec_length(v);
	return ((t_vec3){
		v.x / len,
		v.y / len,
		v.z / len
	});
}
