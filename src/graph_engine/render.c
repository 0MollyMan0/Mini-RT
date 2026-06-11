/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/06/11 14:02:27 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/*Tells who hit the ray*/
static t_hit	who_hit(t_ray ray, t_object *obj)
{
	t_object	*ptr;
	t_hit		hit;
	t_hit		tmp;

	ptr = obj;
	hit.dst = INFINITY;
	hit.is_hit = 0;
	hit.col_obj = init_color(10, 10, 10);
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

static int	calc_shadow(t_hit *hit, t_light light, t_data *data)
{
	t_ray	shadow_ray;
	t_hit	shadow_hit;
	t_vec3	shadow_origin;

	shadow_origin = vec_add(hit->point, vec_mult(hit->normal, 0.0001));
	shadow_ray = calc_ray(shadow_origin, light.pos);
	shadow_hit = who_hit(shadow_ray, data->objects);
	if (shadow_hit.is_hit
		&& shadow_hit.dst < vec_length(vec_sub(light.pos, hit->point)))
		return (1);
	else
		return (0);
}

static void	calc_light_impact(t_hit *hit, t_light light, t_data *data)
{
	if (calc_shadow(hit, light, data))
		hit->diffuse = 0;
	else
	{
		hit->light_dir = vec_normalize(vec_sub(light.pos, hit->point));
		hit->diffuse = double_clamp(vec_dot(hit->normal, hit->light_dir), 0, 1);
	}
	hit->col_final = color_mix(hit->col_obj, light.color, light.brightness);
	hit->col_final = color_mult(hit->col_final, hit->diffuse);
}

/*Give the color for each pixel*/
static int	get_color(t_ray ray, t_data *data)
{
	t_hit	hit;

	hit = who_hit(ray, data->objects); // tells if ray it an obj
	if (!hit.is_hit) // if no obj hit return background color
		return (hit.col_obj.hex);

	hit.col_ambient = color_mix(hit.col_obj, // calc impact of ambient light
		data->scene.al.color, data->scene.al.brightness);

	calc_light_impact(&hit, data->scene.light, data); // calc impact of direct light
	hit.col_final = color_add(hit.col_final, hit.col_ambient);
	return (hit.col_final.hex);
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
			ray = calc_ray_cam(x_to_sx(x, data->scene.cam.fov),
					y_to_sy(y, data->scene.cam.fov), data);
			put_pixel(data->mlx->img, x, y, get_color(ray, data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img->img, 0, 0);
}
