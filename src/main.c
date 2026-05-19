/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:33:52 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/19 09:00:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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
	render(data);
	set_controls(data);
	mlx_loop(data->mlx->mlx);
	return (0);
}
