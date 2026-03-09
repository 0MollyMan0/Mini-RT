/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 10:13:44 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_ray	calc_ray(double sx, double sy)
{
	t_ray	ray;
	
	ray.dx = sx;
	ray.dy = sy;
	ray.dz = -1.0;
	ray.len = sqrt(ray.dx*ray.dx + ray.dy*ray.dy + ray.dz*ray.dz);
	ray.dx /= ray.len;
	ray.dy /= ray.len;
	ray.dz /= ray.len;

	return (ray);
}

void	render(t_mlx *mlx)
{
	int		x;
	int		y;
	t_ray	ray;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray = calc_ray(x_to_sx(x), y_to_sy(y));
			int red   = (int)((ray.dx + 1) * 0.5 * 255);
			int green = (int)((ray.dy + 1) * 0.5 * 255);
			int blue  = (int)((ray.dz + 1) * 0.5 * 255);
			put_pixel(mlx->img, x, y, rgb_to_hex(red, green, blue));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);	
}
