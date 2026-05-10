/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 08:46:07 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 11:31:35 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	*parse_sphere(t_data *data, char **tab)
{
	t_sp	*sphere;

	sphere = malloc(sizeof(t_sp));
	if (!sphere)
		ft_exit(data);
	sphere->pos = parse_vec(tab[1]);
	sphere->dia = ft_atof(tab[2]);
	sphere->color = parse_color(tab[3]);
	printf("detect sphere\n");
	return (sphere);
}

static void	*parse_plane(t_data *data, char **tab)
{
	t_pl	*plane;

	plane = malloc(sizeof(t_pl));
	if (!plane)
		ft_exit(data);
	plane->pos = parse_vec(tab[1]);
	plane->n_vec = parse_vec(tab[2]);
	plane->color = parse_color(tab[3]);
	printf("detect plane\n");
	return (plane);
}

static void	*parse_cylinder(t_data *data, char **tab)
{
	t_cy	*cylinder;

	cylinder = malloc(sizeof(t_cy));
	if (!cylinder)
		ft_exit(data);
	cylinder->pos = parse_vec(tab[1]);
	cylinder->n_vec = parse_vec(tab[2]);
	cylinder->dia = ft_atof(tab[3]);
	cylinder->height = ft_atof(tab[4]);
	cylinder->color = parse_color(tab[5]);
	printf("detect cylinder\n");
	return (cylinder);
}

void	parse_objects(t_data *data, char **tab)
{
	void		*shape;
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		ft_exit(data);
	if (!ft_strcmp(tab[0], "pl"))
	{
		obj->type = PLANE;
		shape = parse_plane(data, tab);
	}
	else if (!ft_strcmp(tab[0], "sp"))
	{
		obj->type = SPHERE;
		shape = parse_sphere(data, tab);
	}
	else
	{
		obj->type = CYLINDER;
		shape = parse_cylinder(data, tab);
	}
	objects_add_back(data->objects, obj);
}
