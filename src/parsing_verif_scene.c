/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_scene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 09:14:15 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 09:14:35 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	verif_al(char **tab)
{
	if (!is_double_in_range(ft_atof(tab[1]), 0, 1))
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

static int	verif_light(char **tab)
{
	if (!is_double_in_range(ft_atof(tab[1]), 0, 1))
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

static int	verif_cam(char **tab)
{
	if (!verif_n_vec(tab[2]))
	{
		print_error(ERR_CAM, ERR_N_VECTOR);
		return (0);
	}
	if (!is_int_in_range(ft_atoi(tab[3]), 0, 180))
	{
		print_error(ERR_CAM, ERR_FOV);
		return (0);	
	}
	return (1);
}
