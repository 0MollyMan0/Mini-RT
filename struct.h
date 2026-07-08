/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:20:36 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/08 13:21:26 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H

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
}	t_parse_error;

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
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	int		hex;
}	t_color;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
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
	t_vec3	forward;
	t_vec3	up;
	t_vec3	right;
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

typedef struct s_hit
{
	t_color	col_final;
	t_color	col_obj;
	t_color	col_ambient;
	t_vec3	point;
	t_vec3	normal;
	t_vec3	light_dir;
	double	diffuse;
	double	dst;
	int		is_hit;
}				t_hit;

typedef struct s_parsing
{
	int			fd;
	int			err;
	char		*line;
}				t_parsing;

typedef struct s_data
{
	t_mlx		*mlx;
	t_scene		scene;
	t_object	*objects;
	t_is		is;
	t_parsing	parsing;
	unsigned	pixelization;
}				t_data;

#endif