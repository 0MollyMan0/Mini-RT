/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 14:14:53 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	calc_delta(double b, double c)
{
	return ((b * b) - 4 * 1 * c);
}

double calc_b(t_ray ray, t_sphere sphere, t_data data)
{
	double	x;
	double	y;	
	double	z;

	x = (data.cam.x - sphere.c.x) * ray.dir.x;
	y = (data.cam.y - sphere.c.y) * ray.dir.y;
	z = (data.cam.z - sphere.c.z) * ray.dir.z;
	return (2 * (x + y + z));
}

double calc_c(t_sphere sphere, t_data data)
{
	double	x;
	double	y;	
	double	z;

	x = (data.cam.x - sphere.c.x) * (data.cam.x - sphere.c.x);
	y = (data.cam.y - sphere.c.y) * (data.cam.y - sphere.c.y);
	z = (data.cam.z - sphere.c.z) * (data.cam.z - sphere.c.z);
	return (x + y + z - (sphere.r * sphere.r));
}

static int	hit_sphere(t_ray ray, t_sphere sphere, t_data data)
{
	int	delta;

	delta = calc_delta(calc_b(ray, sphere, data), calc_c(sphere, data));
	if (delta >= 0)
		return (1);
	return (0);
}

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
