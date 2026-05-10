/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 09:13:30 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 15:19:45 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	verif_cylinder(char **tab)
{
	int	res;

	res = 1;
	if (!verif_vec_syntax(tab[1]))
		res = print_error(ERR_CYLINDER, ERR_SYNTAX, tab[1]);
	else if (!verif_n_vec(tab[2]))
		res = print_error(ERR_CYLINDER, ERR_N_VECTOR, tab[2]);
	else if (!is_valid_double(tab[3]))
		res = print_error(ERR_CYLINDER, ERR_SYNTAX, tab[3]);
	else if (!is_valid_double(tab[4]))
		res = print_error(ERR_CYLINDER, ERR_SYNTAX, tab[3]);
	else if (!verif_rgb(tab[5]))
		res = print_error(ERR_CYLINDER, ERR_RGB, tab[4]);
	return (res);
}

int	verif_sphere(char **tab)
{
	int	res;

	res = 1;
	if (!verif_vec_syntax(tab[1]))
		res = print_error(ERR_SPHERE, ERR_SYNTAX, tab[1]);
	else if (!is_valid_double(tab[2]))
		res = print_error(ERR_SPHERE, ERR_SYNTAX, tab[2]);
	else if (!verif_rgb(tab[3]))
		res = print_error(ERR_PLANE, ERR_RGB, tab[3]);
	return (res);
}

int	verif_plane(char **tab)
{
	int	res;

	res = 1;
	if (!verif_vec_syntax(tab[1]))
		res = print_error(ERR_PLANE, ERR_SYNTAX, tab[1]);
	if (!verif_n_vec(tab[2]))
		res = print_error(ERR_PLANE, ERR_N_VECTOR, tab[2]);
	else if (!verif_rgb(tab[3]))
		res = print_error(ERR_PLANE, ERR_RGB, tab[3]);
	return (res);
}
