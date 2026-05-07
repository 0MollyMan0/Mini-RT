/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:10:41 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/07 16:33:30 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	print_error(t_parse_error concerned, t_parse_error problem)
{
	ft_putstr_fd("Error\n", 2);
	switch (concerned)
	{
	case ERR_SPHERE:
		ft_putstr_fd("Sphere problem: ", 2);
		break;
	case ERR_PLANE:
		ft_putstr_fd("Plane problem: ", 2);
		break;
	case ERR_CYLINDER:
		ft_putstr_fd("Sphere problem: ", 2);
		break;
		
	default:
		break;
	}
}

void	print_error(t_parse_error concerned, t_parse_error problem)
{
	ft_putstr_fd("Error\n", 2);
	if (concerned == ERR_SPHERE)
		ft_putstr_fd("Sphere problem: ", 2);
	else if (concerned == ERR_PLANE)
		ft_putstr_fd("Plane problem: ", 2);
	else if (concerned == ERR_CYLINDER)
		ft_putstr_fd("Cylinder problem: ", 2);
	else if (concerned == ERR_AMBIENT_LIGHT)
		ft_putstr_fd("Ambient Light problem: ", 2);
	else if (concerned == ERR_LIGHT)
		ft_putstr_fd("Light problem: ", 2);
	else if (concerned == ERR_CAM)
		ft_putstr_fd("Camera problem: ", 2);
	if (problem == ERR_RGB)
		ft_putstr_fd("color has to be in the range [0,255]", 2);
	else if (problem == ERR_N_VECTOR)
		ft_putstr_fd("3D normalized orientation vector"
			"has to be in the range [-1,1]", 2);
	else if (problem == ERR_FOV)
		ft_putstr_fd("FOV has to be in the range [0,180]", 2);
	else if (problem == ERR_LIGHT_RATIO)
		ft_putstr_fd("FOV has to be in the range [0.0,1.0]", 2);
}
