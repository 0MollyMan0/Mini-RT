/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:44:46 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/12 14:32:24 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3	parse_vec(char *str)
{
	char	**sub_tab;
	t_vec3	vec;

	sub_tab = ft_split(str, ',');
	if (!sub_tab)
		return (init_vec(1, 1, 1));
	vec.x = ft_atof(sub_tab[0]);
	vec.y = ft_atof(sub_tab[1]);
	vec.z = ft_atof(sub_tab[2]);
	free_str_tab(sub_tab);
	return (vec);
}

t_color	parse_color(char *str)
{
	char	**sub_tab;
	t_color	color;

	sub_tab = ft_split(str, ',');
	if (!sub_tab)
		return (init_color(255, 255, 255));
	color.r = ft_atof(sub_tab[0]);
	color.g = ft_atof(sub_tab[1]);
	color.b = ft_atof(sub_tab[2]);
	color.hex = rgb_to_hex(ft_atoi(sub_tab[0]), 
	ft_atoi(sub_tab[1]), ft_atoi(sub_tab[2]));
	free_str_tab(sub_tab);
	return (color);
}
