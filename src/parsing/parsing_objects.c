/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 08:46:07 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 11:00:29 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	parse_cylinder(t_data *data, char **tab)
{
	(void)data;
	(void)tab;
	printf("detect cylinder\n");
}

static void	parse_sphere(t_data *data, char **tab)
{
	(void)data;
	(void)tab;
	printf("detect sphere\n");
}

static void	parse_plane(t_data *data, char **tab)
{
	(void)data;
	(void)tab;
	printf("detect plane\n");
}

void	parse_objects(t_data *data, char **tab)
{
	if (!ft_strcmp(tab[0], "cy"))
		parse_cylinder(data, tab);
	else if (!ft_strcmp(tab[0], "sp"))
		parse_sphere(data, tab);
	else
		parse_plane(data, tab);
}
