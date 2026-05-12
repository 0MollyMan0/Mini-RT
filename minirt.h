/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:04:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/12 14:28:03 by anfouger         ###   ########.fr       */
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
# define M_PI 3.14159265358979323846

typedef enum e_parse_error
{
	ERR_INVALID_ID,
	ERR_FILE_NAME,
	ERR_SPECIAL,
	ERR_SYNTAX,
    ERR_SPHERE,
	ERR_PLANE,
	ERR_CYLINDER,
	ERR_AMBIENT_LIGHT,
	ERR_LIGHT,
	ERR_CAM,
    ERR_RGB,
    ERR_FOV,
	ERR_LIGHT_RATIO,
    ERR_N_VECTOR,
	ERR_NONE,
	ERR_TOO_MUCH,
} t_parse_error;

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

typedef struct s_color
{
    double r;
    double g;
    double b;
} t_color;

typedef struct s_ray
{
    t_vec3 origin;
    t_vec3 dir;
}				t_ray;

typedef struct s_sp
{
	double	dia;
	t_vec3	c;
	t_color	color;
}				t_sp;

typedef struct s_pl
{
	t_vec3	pos;
	t_vec3	n_vec;
	t_color	color;
}				t_pl;

typedef struct s_cy
{
	t_vec3	pos;
	t_vec3	n_vec;
	double	dia;
	double	height;
	t_color	color;
}				t_cy;

typedef struct s_object
{
	t_object_type		type;
	void				*shape;
	struct s_object		*next;
}				t_object;

typedef struct s_cam
{
	t_vec3	pos;
	t_vec3	n_orientation;
	int		fov;
}				t_cam;

typedef struct s_al
{
	double	brightness;
	t_color	color;
}				t_al;

typedef struct s_light
{
	t_vec3	pos;
	double	brightness;
	t_color	color;
}				t_light;

typedef struct s_scene
{
	t_al		al;
	t_cam		cam;	
	t_light		light;
}				t_scene;

typedef struct s_is
{
	int		al;
	int		cam;	
	int		light;
	int		plane;
	int		sphere;
	int		cylinder;
	int		fd_open;
}				t_is;

typedef struct s_data
{
	t_mlx		*mlx;
	t_scene		scene;
	t_object	*objects;
	t_is		is;
	int			fd;
}				t_data;

// --- Init --- //
t_mlx		*init_mlx(void);
t_data		*init_data(void);

// --- Init Helpers --- //
t_vec3		init_vec(double x, double y, double z);
t_color		init_color(double r, double g, double b);

// --- Parsing --- //
void		parse_file(char *name, t_data *data);
void		parse_scene(t_data *data, char **tab);
void		parse_objects(t_data *data, char **tab);
// - Utils - //
t_color		parse_color(char *str);
t_vec3		parse_vec(char *str);

// --- Verif Parsing --- //
int			verif_line(char **tab);
int			verif_file_name(char *str);
int			verif_complete(t_is is);
int			verif_cylinder(char **tab);
int			verif_sphere(char **tab);
int			verif_plane(char **tab);
int			verif_al(char **tab);
int			verif_light(char **tab);
int			verif_cam(char **tab);
// - Utils - //
int			verif_n_vec(char *str);
int			verif_rgb(char *str);
int			verif_fov(char *str);
int			verif_light_ratio(char *str);
// - Syntax - //
int			verif_vec_syntax(char *str);
int			verif_rgb_syntax(char *str);

// --- Sphere --- //
double		hit_sphere(t_ray ray, t_sp sphere);

// --- Rays --- //
t_ray		calc_ray(double sx, double sy, t_data *data);

// --- Objects ---xs
void		obj_add_back(t_object **lst, t_object *new);

// --- Render --- //
void		render(t_data *data);

// --- Render Utils--- //
int			rgb_to_hex(int red, int green, int blue);
void		put_pixel(t_img *img, int x, int y, int color);
double		x_to_sx(int x, int FOV);
double		y_to_sy(int y, int FOV);

// --- Controls --- //
void		set_controls(t_data *data);

// --- Exit --- //
int			ft_exit(t_data *data);

// --- Error Handling --- //
int			print_error(t_parse_error concerned, t_parse_error problem, char *str);

// --- Random Utils --- //
int			ft_strlen_until(char *str, char c);
int			is_double_in_range(double x, double min, double max);
int			is_int_in_range(int x, int min, int max);

#endif