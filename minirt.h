/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:04:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/09 14:56:44 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

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

typedef struct s_sphere
{
	double	r;
	t_vec3	c;
}				t_sphere;

typedef struct s_data
{
	t_mlx	*mlx;
	t_vec3	cam;
}				t_data;

// --- Init --- //
t_mlx		*init_mlx(void);
t_data		init_data(void);

// --- Sphere --- //
int			hit_sphere(t_ray ray, t_sphere sphere, t_data data);
double		calc_c(t_sphere sphere, t_data data);
t_sphere	init_sphere(void);
double		calc_delta(double b, double c);
double		calc_b(t_ray ray, t_sphere sphere, t_data data);

// --- Render --- //
void		render(t_data data);

// --- Render Utils--- //
int			rgb_to_hex(int red, int green, int blue);
void		put_pixel(t_img *img, int x, int y, int color);
double		x_to_sx(int x);
double		y_to_sy(int y);

// --- Controls --- //
void		set_controls(t_data data);

// --- Exit --- //
int			ft_exit(t_mlx *mlx);

#endif