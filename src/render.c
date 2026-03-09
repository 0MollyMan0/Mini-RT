/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 14:54:17 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_ray	calc_ray(double sx, double sy)
{
	t_ray	ray;
	double	len;

	ray.dir.x = sx;
	ray.dir.y = sy;
	ray.dir.z = -1.0;
	len = sqrt(ray.dir.x*ray.dir.x + ray.dir.y*ray.dir.y
		+ ray.dir.z*ray.dir.z);
	ray.dir.x /= len;
	ray.dir.y /= len;
	ray.dir.z /= len;

	return (ray);
}

void	render(t_data data)
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
			ray = calc_ray(x_to_sx(x), y_to_sy(y));
			int red = hit_sphere(ray, sphere, data) * 255;
			put_pixel(data.mlx->img, x, y, rgb_to_hex(red, 0, 0));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx->mlx, data.mlx->win,
		data.mlx->img->img, 0, 0);	
}
