/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:10:41 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/12 10:06:08 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	print_error_concerned(t_parse_error concerned)
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

static void	print_error_problem_2(t_parse_error problem)
{
	switch (problem)
	{
	case ERR_NONE:
		ft_putstr_fd("Not enougth\n", 2);
		break;
	case ERR_TOO_MUCH:
		ft_putstr_fd("Too much\n", 2);
		break;
	default:
		break;
	}
}

static void	print_error_problem(t_parse_error problem)
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

static void	print_error_special(t_parse_error concerned, char *str)
{
	if (concerned == ERR_INVALID_ID)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\e[0m: is not a valid identifier\n", 2);
	}
	else if (concerned == ERR_FILE_NAME)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\e[0m: is not a valid file name\n", 2);
	}
}

int	print_error(t_parse_error concerned, t_parse_error problem, char *str)
{
	ft_putstr_fd("\e[1;31m", 2);
	ft_putstr_fd("Error\n", 2);
	if (problem == ERR_SPECIAL)
	{
		print_error_special(concerned, str);
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
