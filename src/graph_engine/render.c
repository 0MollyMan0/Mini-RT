/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/13 08:21:10 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*Tells who hit the ray*/
static t_hit	who_hit(t_ray ray, t_data* data, t_object *obj)
{
	(void)		data;
	t_object	*ptr;
	t_hit		hit;
	t_hit		tmp;
	
	ptr = obj;
	hit.dst = INFINITY;
	hit.color = init_color(0, 0, 0);
	while (ptr)
	{
		if (ptr->type == SPHERE)
			tmp = hit_sphere(ray, (t_sp *)ptr->shape);
		// else if (ptr->type == CYLINDER)
		// 	tmp_dst = hit_cylinder(ray, (t_cy *)ptr->shape);
		// else if (ptr->type == PLANE)
		// 	tmp_dst = hit_plane(ray, (t_pl *)ptr->shape);
		if (tmp.dst > 0 && tmp.dst < hit.dst)
			hit = tmp;
		ptr = ptr->next;
	}
	return (hit);
}

/*Give the color for each pixel*/
static int	get_color(t_ray ray, t_data* data)
{
	t_hit	hit;

	hit = who_hit(ray, data, data->objects);
	// calc_light_impact
	// calc_al_impact
	return (hit.color.hex);
}

/*main loop to render*/
void	render(t_data *data)
{
	int			x;
	int			y;
	t_ray		ray;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray = calc_ray(x_to_sx(x, data->scene.cam.fov),
				y_to_sy(y, data->scene.cam.fov), data);
			put_pixel(data->mlx->img, x, y, get_color(ray, data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img->img, 0, 0);
}
