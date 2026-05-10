/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_scene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 09:14:15 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 09:32:31 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	verif_al(char **tab)
{
	if (!verif_light_ratio(tab[1]))
	{
		print_error(ERR_AMBIENT_LIGHT, ERR_LIGHT_RATIO);
		return (0);	
	}
	else if (!verif_rgb(tab[2]))
	{
		print_error(ERR_AMBIENT_LIGHT, ERR_RGB);
		return (0);	
	}
	return (1);
}

int	verif_light(char **tab)
{
	if (!verif_light_ratio(tab[2]))
	{
		print_error(ERR_LIGHT, ERR_LIGHT_RATIO);
		return (0);	
	}
	else if (!verif_rgb(tab[3]))
	{
		print_error(ERR_LIGHT, ERR_RGB);
		return (0);	
	}
	return (1);
}

int	verif_cam(char **tab)
{
	if (!verif_n_vec(tab[2]))
	{
		print_error(ERR_CAM, ERR_N_VECTOR);
		return (0);
	}
	if (!verif_FOV(tab[3]))
	{
		print_error(ERR_CAM, ERR_FOV);
		return (0);	
	}
	return (1);
}
