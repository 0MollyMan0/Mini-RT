/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:47:45 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/05 11:56:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	render(t_mlx *mlx)
{
	int x;
	int y;
	
	y = 0;
	while (y < 50)
	{
		x = 0;
		while (x < 50)
		{
			put_pixel(mlx->img, 400+x, 300+y, 0x00FF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);	
}
