/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/11 10:28:57 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	get_color(t_ray ray, t_sp *sphere, t_data *data)
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
		t = hit_sp(ray, sphere[i]);
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

void	render(t_data *data)
{
	int			x;
	int			y;
	t_ray		ray;
	t_sp	*sphere;

	sphere = init_obj_test(data);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray = calc_ray(x_to_sx(x, data->scene.cam.fov),
				y_to_sy(y, data->scene.cam.fov), data);
			put_pixel(data->mlx->img, x, y, get_color(ray, sphere, data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img->img, 0, 0);
	free(sphere);
}
