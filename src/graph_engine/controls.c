/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:02:00 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/13 14:24:40 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	update_pos(t_vec3 *pos, t_vec3 dir, int sign)
{
	dir = vec_normalize(dir);
	if (sign > 0)
	{
		pos->x += dir.x * KEY_SENSI;
		pos->y += dir.y * KEY_SENSI;
		pos->z += dir.z * KEY_SENSI;
	}
	else
	{
		pos->x -= dir.x * KEY_SENSI;
		pos->y -= dir.y * KEY_SENSI;
		pos->z -= dir.z * KEY_SENSI;
	}
}

static void move_cam(int keycode, t_cam *cam)
{
	if (keycode == 's')
		update_pos(&cam->pos, cam->forward, -1);
	else if (keycode == 'w')
		update_pos(&cam->pos, cam->forward, 1);
	else if (keycode == 'a')
		update_pos(&cam->pos, cam->right, -1);
	else if (keycode == 'd')
		update_pos(&cam->pos, cam->right, 1);
	else if (keycode == 'q')
		update_pos(&cam->pos, cam->up, -1);
	else if (keycode == 'e')
		update_pos(&cam->pos, cam->up, 1);
}

static void mouse_hook(int button, int x, int y, t_cam *cam)
{
	static double	last_x;
	static double	last_y;
	double	delta_x;
	double	delta_y;

	delta_x = x - last_x;
	delta_y = y - last_y;
	cam->yaw += delta_x * MOUSE_SENSI;
	cam->pitch += delta_y * MOUSE_SENSI;
	cam->forward.x = cos(cam->pitch) * cos(cam->yaw);
	cam->forward.y = sin(cam->pitch);
	cam->forward.z = cos(cam->pitch) * sin(cam->yaw);
}

static int	ft_key_pressed(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data);
	else if (keycode == 'a' || keycode == 'd' || keycode == 's'
		|| keycode == 'w' || keycode == 'e' || keycode == 'q')
		move_cam(keycode, &data->scene.cam);
	render(data);
	return (0);
}

void	set_controls(t_data *data)
{
	mlx_hook(data->mlx->win, 17, 0, ft_exit, data);
	mlx_hook(data->mlx->win, 2, 1L << 0, ft_key_pressed, data);
	mlx_hook(data->mlx->win, 6, 1L<<6, mouse_hook, data);
}
