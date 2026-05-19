/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:48:00 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/19 09:06:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_hit	hit_plane(t_ray ray, t_pl *plane)
{
	t_hit	hit;

	(void)plane;
	(void)ray;
	hit.dst = -1;
	hit.col_obj = init_color(0, 0, 0);
	return (hit);
}
