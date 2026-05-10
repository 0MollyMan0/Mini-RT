/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:10:41 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 14:19:49 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	print_error_concerned(t_parse_error concerned)
{
	switch (concerned)
	{
	case ERR_SPHERE:
		ft_putstr_fd("Sphere problem: ", 2);
		break;
	case ERR_PLANE:
		ft_putstr_fd("Plane problem: ", 2);
		break;
	case ERR_CYLINDER:
		ft_putstr_fd("Cylinder problem: ", 2);
		break;
	case ERR_AMBIENT_LIGHT:
		ft_putstr_fd("Ambient Light problem: ", 2);
		break;
	case ERR_LIGHT:
		ft_putstr_fd("Light problem: ", 2);
		break;
	case ERR_CAM:
		ft_putstr_fd("Camera problem: ", 2);
		break;
	default:
		break;
	}
}

void	print_error_problem(t_parse_error problem)
{
	switch (problem)
	{
	case ERR_RGB:
		ft_putstr_fd("Color has to be in the range "
			"\e[0;32m[0,255]\n", 2);
		break;
	case ERR_FOV:
		ft_putstr_fd("FOV has to be in the range "
			"\e[0;32m[0,180]\n", 2);
		break;
	case ERR_N_VECTOR:
		ft_putstr_fd("3D normalized orientation vector "
			"has to be in the range \e[0;32m[-1,1]\n", 2);
		break;
	case ERR_LIGHT_RATIO:
		ft_putstr_fd("Light ratio has to be in the range"
			" \e[0;32m[0.0,1.0]\n", 2);
		break;
	case ERR_SYNTAX:
		ft_putstr_fd("Syntax problem\n", 2);
		break;
	default:
		break;
	}
}

int	print_error(t_parse_error concerned, t_parse_error problem, char *str)
{
	ft_putstr_fd("\e[1;31m", 2);
	ft_putstr_fd("Error\n", 2);
	if (concerned == ERR_INVALID_ID)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": is not a valid identifier\e[0m\n", 2);
		return (0);
	}
	ft_putstr_fd("\e[1;37m", 2);
	print_error_concerned(concerned);
	ft_putstr_fd("\e[1;31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\e[1;37m\n", 2);
	print_error_problem(problem);
	ft_putstr_fd("\e[0m", 2);
	return (0);
}
