/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:37:51 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/19 08:29:40 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int inline	rgb_to_hex(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

/* Converts the x-coordinate of a pixel on the screen to
the x-coordinate of a normalized mathematical plane*/
double	x_to_sx(int x, int FOV)
{
	double	nx;
	double	sx;
	double	aspect_ratio;
	double	fov_rad;

	nx = ((double)x + 0.5) / (WIN_WIDTH - 1);
	sx = 2.0 * nx - 1.0;
	aspect_ratio = (double)WIN_WIDTH / WIN_HEIGHT;
	sx *= aspect_ratio;
	fov_rad = (FOV * M_PI) / 180.0;
	sx *= tan(fov_rad / 2.0);
	return (sx);
}

/* Converts the y-coordinate of a pixel on the screen to
the y-coordinate of a normalized mathematical plane*/
double	y_to_sy(int y, int FOV)
{
	double	ny;
	double	sy;
	double	fov_rad;

	ny = ((double)y + 0.5) / (WIN_HEIGHT - 1);
	sy = 1.0 - 2.0 * ny;
	fov_rad = (FOV * M_PI) / 180.0;
	sy *= tan(fov_rad / 2.0);
	return (sy);
}
