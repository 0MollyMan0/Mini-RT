/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 09:56:20 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	render(t_mlx *mlx)
{
	int		x;
	int		y;
	double	sx;
	double	sy;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			sx = x_to_sx(x);
			sy = y_to_sy(y);
			double dx = sx;
			double dy = sy;
			double dz = -1.0;
			double len = sqrt(dx*dx + dy*dy + dz*dz);
			dx /= len;
			dy /= len;
			dz /= len;
			int red   = (int)((dx + 1) * 0.5 * 255);
			int green = (int)((dy + 1) * 0.5 * 255);
			int blue  = (int)((dz + 1) * 0.5 * 255);
			put_pixel(mlx->img, x, y, rgb_to_hex(red, green, blue));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);	
}
