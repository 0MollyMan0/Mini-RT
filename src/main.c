/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/07 14:31:53 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	print_data(t_data *data)
{
	printf("al_brightness = %d", data->scene.al_brightness);
	printf("al_color = %i", data->scene.al_color);
	printf("cam_pos = %d,%d,%d\n", data->scene.cam_pos.x, data->scene.cam_pos.y, data->scene.cam_pos.z);
	printf("cam_n_orientation = %d,%d,%d\n", data->scene.cam_n_orientation.x, data->scene.cam_n_orientation.y, data->scene.cam_n_orientation.z);
	printf("cam_fov = %i", data->scene.cam_fov);
	printf("l_pos = %d,%d,%d\n", data->scene.l_pos.x, data->scene.l_pos.y, data->scene.l_pos.z);
	printf("l_brightness = %d", data->scene.l_brightness);
	printf("l_color = %i", data->scene.l_color);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (1);
	data = init_data();
	if (!data)
	{
		ft_exit(data);
		return (1);
	}
	parse_file(av[1], data);
	print_data(data);
	// render(data);
	// set_controls(data);
	// mlx_loop(data->mlx->mlx);
	return (0);
}
