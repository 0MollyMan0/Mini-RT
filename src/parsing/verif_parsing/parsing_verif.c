/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:28:37 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/13 08:41:29 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	verif_complete(t_is	is)
{
	if (!is.al)
		return (print_error(ERR_AMBIENT_LIGHT, ERR_NONE, NULL));
	else if (!is.cam)
		return (print_error(ERR_CAM, ERR_NONE, NULL));
	else if (!is.light)
		return (print_error(ERR_LIGHT, ERR_NONE, NULL));
	else if (is.al > 1)
		return (print_error(ERR_AMBIENT_LIGHT, ERR_TOO_MUCH, NULL));
	else if (is.cam > 1)
		return (print_error(ERR_CAM, ERR_TOO_MUCH, NULL));
	else if (is.light > 1)
		return (print_error(ERR_LIGHT, ERR_TOO_MUCH, NULL));
	return (1);
}

int	verif_file_name(char *name)
{
	int	i;

	i = 0;
	while (name[i+3])
		i++;
	if (name[i] == '.' && name[i+1] == 'r' && name[i+2] == 't')
		return (1);
	else
	{
		print_error(ERR_FILE_NAME, ERR_SPECIAL, name);
		return (0);
	}
	return (1);
}

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
		print_error(ERR_INVALID_ID, ERR_SPECIAL, tab[0]);
		res = 0;
	}
	return (res);
}
