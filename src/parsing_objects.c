/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 08:46:07 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/24 09:54:10 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	parse_cylinder(t_data *data, char **tab)
{
	(void)data;
	(void)tab;
	printf("detect cylinder\n");
	return (1);
}

static int	parse_sphere(t_data *data, char **tab)
{
	(void)data;
	(void)tab;
	printf("detect sphere\n");
	return (1);
}

static int	parse_plane(t_data *data, char **tab)
{
	(void)data;
	(void)tab;
	printf("detect plane\n");
	return (1);
}

int	parse_objects(t_data *data, char **tab)
{
	int	res;

	if (!ft_strcmp(tab[0], "cy"))
		res = parse_cylinder(data, tab);
	else if (!ft_strcmp(tab[0], "sp"))
		res = parse_sphere(data, tab);
	else
		res = parse_plane(data, tab);
	return (res);
}
