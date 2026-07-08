/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:52:57 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/08 13:53:34 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	update_pos(t_vec3 *pos, t_vec3 dir, int sign)
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

void	move_cam(int keycode, t_cam *cam)
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
