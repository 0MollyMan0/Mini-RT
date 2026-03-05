/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/05 14:15:14 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	render(t_mlx *mlx)
{
	int x;
	int y;
	
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			double nx = (double)x / (WIN_WIDTH - 1);
			double ny = (double)y / (WIN_HEIGHT - 1);
			double sx = 2.0 * nx - 1.0;
			double sy = 1.0 - 2.0 * ny;
			int red   = (int)((sx + 1) * 0.5 * 255);
			int green = (int)((sy + 1) * 0.5 * 255);
			int blue  = 0;
			put_pixel(mlx->img, x, y, get_color(red, green, blue));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);	
}
