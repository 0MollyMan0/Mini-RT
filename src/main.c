/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/13 15:00:20 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
// void	print_al(t_al al);
// void	print_cam(t_cam cam);
// void	print_light(t_light light);
// void	print_data(t_data *data);

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
	// print_data(data);
	render(data);
	set_controls(data);
	mlx_loop(data->mlx->mlx);
	return (0);
}

// void	print_al(t_al al)
// {
// 	printf("// --- Ambient Light --- //\n");
// 	printf("al.brightness = %f\n",
// 		al.brightness);
// 	printf("al.color: R = %f, G = %f, B = %f\n",
// 		al.color.r, al.color.g, al.color.b);
// }

// void	print_cam(t_cam cam)
// {
// 	printf("// --- Camera --- //\n");
// 	printf("cam.pos = %f,%f,%f\n",
// 		cam.pos.x, cam.pos.y, cam.pos.z);
// 	printf("cam.n_orientation = %f,%f,%f\n",
// 		cam.n_orientation.x, cam.n_orientation.y, cam.n_orientation.z);
// 	printf("cam.fov = %i\n",
// 		cam.fov);
// }

// void	print_light(t_light light)
// {
// 	printf("// --- Light --- //\n");
// 	printf("light.pos = %f,%f,%f\n",
// 		light.pos.x,light.pos.y, light.pos.z);
// 	printf("light.brightness = %f\n",
// 		light.brightness);
// 	printf("light.color: R = %f, G = %f, B = %f\n",
// 		light.color.r, light.color.g, light.color.b);
// }

// void	print_data(t_data *data)
// {
// 	print_al(data->scene.al);
// 	print_cam(data->scene.cam);
// 	print_light(data->scene.light);
// }
