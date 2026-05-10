/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:28:37 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 13:11:37 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	verif_scene(char **tab)
{
	int	res;

	if (!ft_strcmp(tab[0], "A"))
		res = verif_al(tab);
	else if (!ft_strcmp(tab[0], "L"))
		res = verif_light(tab);
	else
		res = verif_cam(tab);
	return (res);
}

static int	verif_objects(char **tab)
{
	int	res;

	if (!ft_strcmp(tab[0], "cy"))
		res = verif_cylinder(tab);
	else if (!ft_strcmp(tab[0], "sp"))
		res = verif_sphere(tab);
	else
		res = verif_plane(tab);
	return (res);
}

int	verif_line(char **tab)
{
	int	res;

	if (!tab)
		return (0);
	if (!ft_strcmp(tab[0], "sp") || !ft_strcmp(tab[0], "pl")
		|| !ft_strcmp(tab[0], "cy"))
		res = verif_objects(tab);
	else if (!ft_strcmp(tab[0], "A") || !ft_strcmp(tab[0], "C")
		|| !ft_strcmp(tab[0], "L"))
		res = verif_scene(tab);
	else
	{
		print_error(ERR_INVALID_ID, ERR_NONE, tab[0]);
		res = 0;	
	}
	return (res);
}
