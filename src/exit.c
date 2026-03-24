/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:03:35 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/24 08:54:55 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	print_type_exit(int type)
{
	if (type == 1)
		printf("Error\n misconfiguration encountered in the file\n");
	else if (type == 2)
		printf("Error\n malloc failed\n");
}

int	ft_exit(t_data *data, int type)
{
	print_type_exit(type);
	if (data->mlx->win)
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	if (data->mlx->img->img)
		mlx_destroy_image(data->mlx->mlx, data->mlx->img->img);
	mlx_destroy_display(data->mlx->mlx);
	free(data->mlx->img);
	free(data->mlx->mlx);
	free(data->mlx);
	free(data);
	exit(0);
	return (0);
}
