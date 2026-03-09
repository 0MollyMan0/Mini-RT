/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 14:15:28 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(void)
{
	t_mlx *mlx;
	t_data	data;

	mlx = init_mlx();
	data = init_data();
	data.mlx = mlx;
	render(data);
	set_controls(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
