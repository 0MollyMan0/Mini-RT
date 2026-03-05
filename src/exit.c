/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:03:35 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/05 13:30:44 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	ft_exit(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->img->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->img);
	free(mlx->mlx);
	free(mlx);
	exit(0);
	return (0);
}
