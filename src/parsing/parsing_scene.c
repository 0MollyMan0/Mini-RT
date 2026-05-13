/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 08:46:37 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/13 14:04:18 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	parse_al(t_al *al, char **tab)
{
	al->brightness = ft_atof(tab[1]);
	al->color = parse_color(tab[2]);
}

static void	parse_light(t_light *light, char **tab)
{
	light->pos = parse_vec(tab[1]);
	light->brightness = ft_atof(tab[2]);
	light->color = parse_color(tab[3]);
}

static void	parse_cam(t_cam *cam, char **tab)
{
	cam->pos = parse_vec(tab[1]);
	cam->n_orientation = parse_vec(tab[2]);
	cam->fov = ft_atoi(tab[3]);
	cam->yaw = 0;
	cam->pitch = 0;
}

void	parse_scene(t_data *data, char **tab)
{
	if (!ft_strcmp(tab[0], "A"))
	{
		parse_al(&data->scene.al, tab);
		data->is.al++;
	}
	else if (!ft_strcmp(tab[0], "L"))
	{
		parse_light(&data->scene.light, tab);
		data->is.light++;
	}
	else
	{
		parse_cam(&data->scene.cam, tab);
		data->is.cam++;
	}
}
