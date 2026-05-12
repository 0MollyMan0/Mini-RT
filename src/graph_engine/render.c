/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/12 15:49:53 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_color	who_hit(t_ray ray, t_data* data, t_object *obj)
{
	t_object	*ptr;
	t_hit		hit;
	
	ptr = obj;
	hit.dst = INFINITY;
	while (ptr)
	{
		if (ptr->type == SPHERE)
		{
			if (hit_sphere(ray, (t_sp *)ptr->shape)
				&& hit_sphere(ray, (t_sp *)ptr->shape) < hit.dst)
				hit = hit_sphere(ray, (t_sp *)ptr->shape);
		}
		// else if (ptr->type == CYLINDER)
		// 	tmp_dst = hit_cylinder(ray, (t_cy *)ptr->shape);
		// else if (ptr->type == PLANE)
		// 	tmp_dst = hit_plane(ray, (t_pl *)ptr->shape);
		ptr = ptr->next;	
	}
}

static int	get_color(t_ray ray, t_data* data)
{
	t_color color;

	color = who_hit(ray, data, data->objects);
	// calc_light_impact
	// calc_al_impact
	return (color.hex);
}


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
