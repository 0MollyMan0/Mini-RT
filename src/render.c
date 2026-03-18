/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/18 13:45:54 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	get_color(t_ray ray, t_data *data, t_sphere sphere)
{
	int	color;

	if (hit_sphere(ray, sphere, data))
		color = rgb_to_hex(255, 0, 0);
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
	t_sphere	sphere;

	y = 0;
	sphere = init_sphere();
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray = calc_ray(x_to_sx(x), y_to_sy(y), data);
			put_pixel(data->mlx->img, x, y, get_color(ray, data, sphere));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img->img, 0, 0);	
}
