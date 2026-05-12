/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_scene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 09:14:15 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/12 11:35:42 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	verif_al(char **tab)
{
	int	res;

	res = 1;
	if (!verif_light_ratio(tab[1]))
		res = print_error(ERR_AMBIENT_LIGHT, ERR_LIGHT_RATIO, tab[1]);
	else if (!verif_rgb(tab[2]))
		res = print_error(ERR_AMBIENT_LIGHT, ERR_RGB, tab[2]);
	return (res);
}

int	verif_light(char **tab)
{
	int	res;

	res = 1;
	if (!verif_vec_syntax(tab[1]))
		res = print_error(ERR_LIGHT, ERR_SYNTAX, tab[1]);
	if (!verif_light_ratio(tab[2]))
		res = print_error(ERR_LIGHT, ERR_LIGHT_RATIO, tab[2]);
	else if (!verif_rgb(tab[3]))
		res = print_error(ERR_LIGHT, ERR_RGB, tab[3]);
	return (res);
}

int	verif_cam(char **tab)
{
	int	res;

	res = 1;
	if (!verif_vec_syntax(tab[1]))
		res = print_error(ERR_CAM, ERR_SYNTAX, tab[1]);
	if (!verif_n_vec(tab[2]))
		res = print_error(ERR_CAM, ERR_N_VECTOR, tab[2]);
	if (!verif_fov(tab[3]))
		res = print_error(ERR_CAM, ERR_FOV, tab[3]);
	return (res);
}
