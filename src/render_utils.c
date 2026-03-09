/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:37:51 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 09:21:06 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

double	x_to_sx(int x)
{
	double	nx;
	double	sx;

	nx = (double)x / (WIN_WIDTH - 1);
	sx = 2.0 * nx - 1.0;
	return (sx);
}

double	y_to_sy(int y)
{
	double	ny;
	double	sy;

	ny = (double)y / (WIN_HEIGHT - 1);
	sy = 1.0 - 2.0 * ny;
	return (sy);
}
