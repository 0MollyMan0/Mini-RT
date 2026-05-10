/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 10:50:39 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	print_data(t_data *data)
{
	printf("al.brightness = %f", data->scene.al.brightness);
	printf("al.color: R = %f, G = %f, B = %f", data->scene.al.color.r);
	printf("cam.pos = %f,%f,%f\n", data->scene.cam.pos.x, data->scene.cam.pos.y, data->scene.cam.pos.z);
	printf("cam.n_orientation = %f,%f,%f\n", data->scene.cam.n_orientation.x, data->scene.cam.n_orientation.y, data->scene.cam.n_orientation.z);
	printf("cam.fov = %i", data->scene.cam.fov);
	printf("light.pos = %f,%f,%f\n", data->scene.light.pos.x, data->scene.light.pos.y, data->scene.light.pos.z);
	printf("light.brightness = %f", data->scene.light.brightness);
	printf("light.color: R = %f, G = %f, B = %f", data->scene.light.color);
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
