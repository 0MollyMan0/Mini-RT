/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 09:13:30 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 09:28:05 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	verif_cylinder(char **tab)
{
	if (!verif_n_vec(tab[2]))
	{
		print_error(ERR_CYLINDER, ERR_N_VECTOR);
		return (0);	
	}
	else if (!verif_rgb(tab[4]))
	{
		print_error(ERR_CYLINDER, ERR_RGB);
		return (0);	
	}
	return (1);
}

int	verif_sphere(char **tab)
{
	if (!verif_rgb(tab[3]))
	{
		print_error(ERR_PLANE, ERR_RGB);
		return (0);	
	}
	return (1);
}

int	verif_plane(char **tab)
{	
	if (!verif_n_vec(tab[2]))
	{
		print_error(ERR_PLANE, ERR_N_VECTOR);
		return (0);	
	}
	else if (!verif_rgb(tab[3]))
	{
		print_error(ERR_PLANE, ERR_RGB);
		return (0);	
	}
	return (1);
}
