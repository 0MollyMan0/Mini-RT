/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 09:18:22 by anfouger         ###   ########.fr       */
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
