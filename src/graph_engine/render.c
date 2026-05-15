/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/15 14:26:48 by anfouger         ###   ########.fr       */
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
	hit.color = init_color(50, 50, 50);
	while (ptr)
	{
		if (ptr->type == SPHERE)
			tmp = hit_sphere(ray, (t_sp *)ptr->shape);
		else if (ptr->type == CYLINDER)
			tmp = hit_cylinder(ray, (t_cy *)ptr->shape);
		else if (ptr->type == PLANE)
			tmp = hit_plane(ray, (t_pl *)ptr->shape);
		if (tmp.dst > 0 && tmp.dst < hit.dst)
			hit = tmp;
		ptr = ptr->next;
	}
	return (hit);
}

static void	calc_light_impact(t_hit *hit, t_light light)
{
	hit->light_dir = vec_normalize(vec_sub(light.pos, hit->point));
	hit->diffuse = double_clamp(vec_dot(hit->normal, hit->light_dir), 0, 1);
	hit->color = color_mix(hit->color, light.color, light.brightness);
	hit->color = color_mult(hit->color, hit->diffuse);
	// printf("Normale = %f, %f, %f\n", hit->normal.x, hit->normal.y, hit->normal.z);
	// printf("Diffuse = %f\n", hit->diffuse);
}
// static void	calc_al_impact(t_hit *hit, t_al al)
// {
// 	hit->color = color_mult(hit->color, (al.brightness));
// }

/*Give the color for each pixel*/
static int	get_color(t_ray ray, t_data* data)
{
	t_hit	hit;

	hit = who_hit(ray, data, data->objects);
	if (!hit.is_hit)
		return (hit.color.hex);
	calc_light_impact(&hit, data->scene.light);
	// calc_al_impact(&hit, data->scene.al);
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
