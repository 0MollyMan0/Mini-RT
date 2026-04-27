/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:04:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/04/27 11:47:53 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define FOV 40.0
# define M_PI 3.14159265358979323846

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_object_type;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*img;
}				t_mlx;

typedef struct s_vec3
{
    double x;
    double y;
    double z;
}				t_vec3;

typedef struct s_ray
{
    t_vec3 origin;
    t_vec3 dir;
}				t_ray;

typedef struct s_sp
{
	double	r;
	t_vec3	c;
	int		color;
}				t_sp;

typedef struct s_pl
{
	t_vec3	vec;
	t_vec3	p;
	int		color;
}				t_pl;

typedef struct s_cy
{
	t_vec3	vec;
	t_vec3	c;
	float	diameter;
	float	height;
	int		color;
}				t_cy;

typedef struct s_object
{
	t_object_type		type;
	void				*shape;
	struct s_object		*next;
}				t_object;

typedef struct s_scene
{
	double	al_brightness;
	int		al_color;
	t_vec3	cam_pos;
	t_vec3	cam_n_orientation;
	int		cam_fov;
	t_vec3	l_pos;
	double	l_brightness;
	int		l_color;
}				t_scene;

typedef struct s_data
{
	t_mlx		*mlx;
	t_vec3		cam;
	int			nb_spheres;
	t_scene		scene;
	t_object	*objects;
}				t_data;

// --- Init --- //
t_mlx	*init_mlx(void);
t_data	*init_data(void);
t_vec3	init_vec(int x, int y, int z);

// --- Parsing --- //
void		parse_file(char *name, t_data *data);
int			parse_scene(t_data *data, char **tab);
int			parse_objects(t_data *data, char **tab);

// --- Sphere --- //
int			hit_sphere(t_ray ray, t_sp sphere);
t_sp		init_sphere(t_vec3 center, double r, int color);

// --- Rays --- //
t_ray		calc_ray(double sx, double sy, t_data *data);

// --- Objects ---xs
void	obj_add_back(t_object **lst, t_object *new);

// --- Render --- //
void		render(t_data *data);

// --- Render Utils--- //
int			rgb_to_hex(int red, int green, int blue);
void		put_pixel(t_img *img, int x, int y, int color);
double		x_to_sx(int x);
double		y_to_sy(int y);

// --- Controls --- //
void		set_controls(t_data *data);

// --- Exit --- //
int			ft_exit(t_data *data);

#endif