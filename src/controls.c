/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:02:00 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 10:37:01 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, 17, 0, ft_exit, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, ft_key_pressed, mlx);
}

int	ft_key_pressed(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		ft_exit(mlx);
	render(mlx);
	return (0);
}
