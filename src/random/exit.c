/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:03:35 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/13 08:38:30 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	free_mlx(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->img->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	free(mlx->img);
	free(mlx->mlx);
	free(mlx);
}

static void	free_objects(t_object *obj)
{
	t_object	*next;

	while (obj->next)
	{
		next = obj->next;
		free(obj->shape);
		free(obj);
		obj = next;
	}
	free(obj->shape);
	free(obj);
}

int	ft_exit(t_data *data)
{
	if (data->mlx)
		free_mlx(data->mlx);
	if (data->objects)
		free_objects(data->objects);
	if (data->is.fd_open)
		close(data->parsing.fd);
	if (data->parsing.line)
		free(data->parsing.line);
	if (data)
		free(data);
	exit(1);
}
