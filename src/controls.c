/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:02:00 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 14:48:25 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void move_cam(int keycode, t_data *data)
{
	if (keycode == 'a')
		data->cam.x -= 0.1;
	else if (keycode == 'd')
		data->cam.x += 0.1;
	else if (keycode == 's')
		data->cam.y -= 0.1;
	else if (keycode == 'w')
		data->cam.y += 0.1;
	else if (keycode == 'q')
		data->cam.z -= 0.1;
	else if (keycode == 'e')
		data->cam.z += 0.1;
}

static int	ft_key_pressed(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data->mlx);
	else if (keycode == 'a' || keycode == 'd' || keycode == 's'
		|| keycode == 'w' || keycode == 'e' || keycode == 'q')
		move_cam(keycode, data);
	render(*data);
	return (0);
}

void	set_controls(t_data data)
{
	mlx_hook(data.mlx->win, 17, 0, ft_exit, data.mlx);
	mlx_hook(data.mlx->win, 2, 1L << 0, ft_key_pressed, &data);
}
