/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/19 10:23:00 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	get_color(t_ray ray, t_sphere *sphere, t_data *data)
{
	double			closest_t;
	double			t;
	int				color;
	int				hit_index;
	int				i;

	i = 0;
	closest_t = -1;
	hit_index = -1;
	while (i < data->nb_spheres)
	{
		t = hit_sphere(ray, sphere[i]);
		if (t > 0 && (closest_t < 0 || t < closest_t))
		{
			closest_t = t;
			hit_index = i;
		}
		i++;
	}
	if (hit_index == 0 || hit_index == 1)
		color = sphere[hit_index].color;
	else
	{
		double t = 0.5 * (ray.dir.y + 1.0);
		int blue = (int)(255 * t);
		int white = (int)(255 * (1 - t));
		color = rgb_to_hex(white, white, blue);
	}
	return (color);
}

static t_sphere *init_obj_test(t_data *data)
{
	t_sphere	*sphere;
	t_vec3		center1;
	t_vec3		center2;
	
	data->nb_spheres = 2;
	sphere = malloc(sizeof(t_sphere) * data->nb_spheres);
	center1.x = 0;
	center1.y = 0; 
	center1.z = -3;
	center2.x = 0;
	center2.y = 0;
	center2.z = -5;
	sphere[0] = init_sphere(center1, 0.5, rgb_to_hex(250, 50, 50));
	sphere[1] = init_sphere(center2, 1, rgb_to_hex(50, 50, 250));
	return (sphere);
}

void	render(t_data *data)
{
	int			x;
	int			y;
	t_ray		ray;
	t_sphere	*sphere;

	sphere = init_obj_test(data);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray = calc_ray(x_to_sx(x), y_to_sy(y), data);
			put_pixel(data->mlx->img, x, y, get_color(ray, sphere, data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img->img, 0, 0);
	free(sphere);
}
