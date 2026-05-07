/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:28:37 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/07 15:50:54 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	verif_al(char **tab)
{
	char	**sub_tab;
	int		i;

	if (is_double_in_range(ft_atof(tab[1]), 0, 1))
	{
		printf("Ambient lighting ratio problem\n");
		printf("Value has to be in the range [0.0,1.0]\n");
		return (0);	
	}
	sub_tab = ft_split(tab[2], ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_int_in_range(ft_atoi(sub_tab[i]), 0, 255))
		{
			printf("Ambient lighting color problem\n");
			printf("Value has to be in the range [0,255]\n");
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
		printf("Light brightness ratio problem\n");
		printf("Value has to be in the range [0.0,1.0]\n");
		return (0);	
	}
	sub_tab = ft_split(tab[2], ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_int_in_range(ft_atoi(sub_tab[i]), 0, 255))
		{
			printf("Ligh color problem\n"
				"Value has to be in the range [0,255]\n");
			
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

	sub_tab = ft_split(tab[2], ',');
	i = 0;
	while (i < 3)
	{
		if (!is_double_in_range(ft_atof(sub_tab[i]), 0, 1))
		{
			printf("3D normalized orientation vector problem\n");
			printf("Value has to be in the range [0.0,1.0]\n");
			free_str_tab(sub_tab);
			return (0);	
		}
		i++;
	}
	free_str_tab(sub_tab);
	if (is_int_in_range(ft_atoi(tab[3]), 0, 180))
	{
		printf("Camera FOV problem\n");
		printf("Value has to be in the range [0,180]\n");
		return (0);	
	}
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
	return (1);
}

static int	verif_sphere(char **tab)
{
	return (1);
}

static int	verif_plane(char **tab)
{
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