/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 08:59:16 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/08 08:22:08 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	verif_rgb(char *str)
{
	char	**sub_tab;
	int		i;

	if (!verif_rgb_syntax(str))
		return (0);
	sub_tab = ft_split(str, ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_int_in_range(ft_atof(sub_tab[i]), 0, 255))
		{
			free_str_tab(sub_tab);
			return (0);
		}
		i++;
	}
	free_str_tab(sub_tab);
	return (1);
}

int	verif_n_vec(char *str)
{
	char	**sub_tab;
	int		i;

	i = 0;
	if (!verif_vec_syntax(str))
		return (0);
	sub_tab = ft_split(str, ',');
	i = 0;
	while (sub_tab[i])
	{
		if (!is_double_in_range(ft_atof(sub_tab[i]), -1, 1))
		{
			free_str_tab(sub_tab);
			return (0);
		}
		i++;
	}
	free_str_tab(sub_tab);
	return (1);
}

int	verif_light_ratio(char *str)
{
	double	light_ratio;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	light_ratio = ft_atof(str);
	if (!is_double_in_range(light_ratio, 0, 1))
		return (0);
	return (1);
}

int	verif_fov(char *str)
{
	int	fov;
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	fov = ft_atoi(str);
	if (!is_int_in_range(fov, 0, 180))
		return (0);
	return (1);
}
