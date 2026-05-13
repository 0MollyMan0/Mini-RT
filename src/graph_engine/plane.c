/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:48:00 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/13 08:49:58 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_hit hit_plane(t_ray ray, t_pl *plane)
{
	t_hit	hit;

	hit.dst = -1;
	hit.color = init_color(0,0,0);
	return (hit);
}
