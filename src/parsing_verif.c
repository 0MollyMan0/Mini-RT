/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:28:37 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 08:58:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	verif_al(char **tab)
{
	char	**sub_tab;
	int		i;

	if (!is_double_in_range(ft_atof(tab[1]), 0, 1))
	{
		print_error(ERR_AMBIENT_LIGHT, ERR_LIGHT_RATIO);
		return (0);	
	}
	sub_tab = ft_split(tab[2], ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_int_in_range(ft_atoi(sub_tab[i]), 0, 255))
		{
			print_error(ERR_AMBIENT_LIGHT, ERR_RGB);
			free_str_tab(sub_tab);
			return (0);	
		}
		i++;
	}
	free_str_tab(sub_tab);
	return (1);
	return (1);
}

static int	verif_light(char **tab)
{
	char	**sub_tab;
	int		i;

	if (is_double_in_range(ft_atof(tab[1]), 0, 1))
	{
		print_error(ERR_LIGHT, ERR_LIGHT_RATIO);
		return (0);	
	}
	sub_tab = ft_split(tab[2], ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_int_in_range(ft_atoi(sub_tab[i]), 0, 255))
		{
			print_error(ERR_LIGHT, ERR_RGB);
			free_str_tab(sub_tab);
			return (0);	
		}
		i++;
	}
	return (1);
}

static int	verif_cam(char **tab)
{
	char	**sub_tab;
	int		i;

	if (is_int_in_range(ft_atoi(tab[3]), 0, 180))
	{
		print_error(ERR_CAM, ERR_FOV);
		return (0);	
	}
	sub_tab = ft_split(tab[2], ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_double_in_range(ft_atof(sub_tab[i]), 0, 1))
		{
			print_error(ERR_CAM, ERR_RGB);
			free_str_tab(sub_tab);
			return (0);	
		}
		i++;
	}
	free_str_tab(sub_tab);
	return (1);
}

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

static int	verif_cylinder(char **tab)
{
	char	**sub_tab;
	int		i;

	sub_tab = ft_split(tab[2], ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_double_in_range(ft_atof(sub_tab[i]), 0, 1))
		{
			print_error(ERR_CYLINDER, ERR_RGB);
			free_str_tab(sub_tab);
			return (0);	
		}
		i++;
	}
	free_str_tab(sub_tab);
	return (1);
}

static int	verif_sphere(char **tab)
{
	char	**sub_tab;
	int		i;

	sub_tab = ft_split(tab[2], ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_double_in_range(ft_atof(sub_tab[i]), 0, 1))
		{
			print_error(ERR_SPHERE, ERR_RGB);
			free_str_tab(sub_tab);
			return (0);	
		}
		i++;
	}
	free_str_tab(sub_tab);
	return (1);
}

static int	verif_plane(char **tab)
{	
	char	**sub_tab;
	int		i;

	sub_tab = ft_split(tab[2], ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_double_in_range(ft_atof(sub_tab[i]), 0, 1))
		{
			print_error(ERR_PLANE, ERR_RGB);
			free_str_tab(sub_tab);
			return (0);	
		}
		i++;
	}
	free_str_tab(sub_tab);
	return (1);
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
