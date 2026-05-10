/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 08:46:37 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 10:32:45 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	parse_al(t_data *data, char **tab)
{
	(void)data;
	(void)tab;
	printf("detect ambient light\n");
}

static void	parse_light(t_data *data, char **tab)
{
	(void)data;
	(void)tab;
	printf("detect light\n");
}

static void	parse_cam(t_data *data, char **tab)
{
	data->scene.cam_pos = parse_vec(tab[1]);
	data->scene.cam_n_orientation = parse_vec(tab[2]);
	data->scene.cam_fov = ft_atoi(tab[3]);
	printf("detect cam\n");
}

void	parse_scene(t_data *data, char **tab)
{
	if (!ft_strcmp(tab[0], "A"))
		parse_al(data, tab);
	else if (!ft_strcmp(tab[0], "L"))
		parse_light(data, tab);
	else
		parse_cam(data, tab);
}
