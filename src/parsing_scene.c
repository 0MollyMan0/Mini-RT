/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 08:46:37 by anfouger          #+#    #+#             */
/*   Updated: 2026/04/27 14:09:47 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	parse_al(t_data *data, char **tab)
{
	(void)data;
	(void)tab;
	printf("detect ambient light\n");
	return (1);
}

static int	parse_light(t_data *data, char **tab)
{
	(void)data;
	(void)tab;
	printf("detect light\n");
	return (1);
}

static int	parse_cam(t_data *data, char **tab)
{
	(void)data;
	char	**tab_pos;

	tab_pos = ft_split(tab[1], ',');
	data->cam = init_vec(ft_atof(tab_pos[0]),
		ft_atof(tab_pos[1]), ft_atof(tab_pos[2]));
	printf("detect cam\n");
	return (1);
}

int	parse_scene(t_data *data, char **tab)
{
	int	res;

	if (!ft_strcmp(tab[0], "A"))
		res = parse_al(data, tab);
	else if (!ft_strcmp(tab[0], "L"))
		res = parse_light(data, tab);
	else
		res = parse_cam(data, tab);
	return (res);
}
