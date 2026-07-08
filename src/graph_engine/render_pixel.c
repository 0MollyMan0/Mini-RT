/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:33:59 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/08 10:01:37 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	render_pixelate(t_data *data)
{
	int				x;
	int				y;
	t_ray			ray;
	unsigned int	block;
	int				color;

	block = data->pixelization + 1;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray = calc_ray_cam(x_to_sx(x, data->scene.cam.fov),
					y_to_sy(y, data->scene.cam.fov), data);
			color = get_color(ray, data);
			fill_block(data, x, y, color);
			x += block;
		}
		y += block;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img->img, 0, 0);
}
