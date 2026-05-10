/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:28:37 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 09:14:33 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	verif_scene(char **tab)
{
	int	res;

	if (!ft_strcmp(tab[0], "A"))
		res = parse_al(tab);
	else if (!ft_strcmp(tab[0], "L"))
		res = parse_light(tab);
	else
		res = parse_cam(tab);
	return (res);
}

int	verif_objects(char **tab)
{
	int	res;

	if (!ft_strcmp(tab[0], "cy"))
		res = parse_cylinder(tab);
	else if (!ft_strcmp(tab[0], "sp"))
		res = parse_sphere(tab);
	else
		res = parse_plane(tab);
	return (res);
}

int	verif_line(char **tab)
{
	int	res;

	if (!ft_strcmp(tab[0], "sp") || !ft_strcmp(tab[0], "pl")
		|| !ft_strcmp(tab[0], "cy"))
		res = verif_objects(tab);
	else if (!ft_strcmp(tab[0], "A") || !ft_strcmp(tab[0], "C")
		|| !ft_strcmp(tab[0], "L"))
		res = verif_scene(tab);
	else
		res = 0;
	return (res);
}
