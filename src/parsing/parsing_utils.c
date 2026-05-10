/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:44:46 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 10:24:58 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vec3	parse_vec(char *str)
{
	char	**sub_tab;
	t_vec3	vec;

	sub_tab = ft_split(str, ',');
	vec.x = ft_atof(sub_tab[0]);
	vec.y = ft_atof(sub_tab[1]);
	vec.z = ft_atof(sub_tab[2]);
	free_str_tab(sub_tab);
	return (vec);
}