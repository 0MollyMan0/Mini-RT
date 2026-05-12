/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:41:24 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/12 10:21:58 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_is	init_is(void)
{
	t_is	is;

	is.al = 0;
	is.cam = 0;
	is.cylinder = 0;
	is.fd_open = 0;
	is.light = 0;
	is.plane = 0;
	is.sphere = 0;
	return (is);
}

t_data *init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = init_mlx();
	data->objects = NULL;
	data->is = init_is();
	return (data);
}

static int	init_img(t_mlx *mlx_data)
{
	mlx_data->img = malloc(sizeof(t_img));
	if (!mlx_data->img)
		return (0);
	mlx_data->img->img = mlx_new_image(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx_data->img->img)
	{
		free(mlx_data->img);
		return (0);	
	}
	mlx_data->img->addr = mlx_get_data_addr(
		mlx_data->img->img,
		&mlx_data->img->bpp,
		&mlx_data->img->line_len,
		&mlx_data->img->endian
	);
	if (!mlx_data->img->addr)
	{
		free(mlx_data->img);
		mlx_destroy_image(mlx_data->mlx, mlx_data->img->img);
		return (0);
	}
	return (1);
}

static int	init_t_mlx(t_mlx *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		return (0);
	mlx_data->win = mlx_new_window(mlx_data->mlx, 
		WIN_WIDTH, WIN_HEIGHT, "miniRT");
	if (!mlx_data->win)
	{
		free(mlx_data->mlx);
		return (0);
	}
	if (!init_img(mlx_data))
	{
		free(mlx_data->mlx);
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		return (0);	
	}
	return (1);
}

t_mlx *init_mlx(void)
{
	t_mlx	*mlx_data;

	mlx_data = malloc(sizeof(t_mlx));
	if (!mlx_data)
		return (NULL);
	if (!init_t_mlx(mlx_data))
	{
		free(mlx_data);
		return (NULL);
	}
	return (mlx_data);
}
