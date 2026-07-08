/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:02:00 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/08 14:33:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	ft_key_pressed(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data);
	else if (keycode == 'a' || keycode == 'd' || keycode == 's'
		|| keycode == 'w' || keycode == 'e' || keycode == 'q')
		move_cam(keycode, &data->scene.cam);
	else if (keycode == 'o' && data->pixelization > 0)
		--data->pixelization;
	else if (keycode == 'p' && data->pixelization <= 10)
		++data->pixelization;
	else if (keycode == KEY_RIGHT)
		rotate_camera_yaw(&data->scene.cam, -ROT_SPEED);
	else if (keycode == KEY_LEFT)
		rotate_camera_yaw(&data->scene.cam, ROT_SPEED);
	else if (keycode == KEY_UP)
		rotate_camera_pitch(&data->scene.cam, ROT_SPEED);
	else if (keycode == KEY_DOWN)
		rotate_camera_pitch(&data->scene.cam, -ROT_SPEED);
	render(data);
	return (0);
}

void	set_controls(t_data *data)
{
	mlx_hook(data->mlx->win, 17, 0, ft_exit, data);
	mlx_hook(data->mlx->win, 2, 1L << 0, ft_key_pressed, data);
}
