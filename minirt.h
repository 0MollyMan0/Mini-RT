/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:04:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/08 14:42:16 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "struct.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define M_PI 3.14159265358979323846
# define KEY_SENSI 0.3
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define ROT_SPEED 2.0

// --- Init --- //
t_mlx	*init_mlx(void);
t_data	*init_data(void);

// --- Init Helpers --- //
t_vec3	init_vec(double x, double y, double z);
t_color	init_color(double r, double g, double b);

// --- Parsing --- //
void	parse_file(char *name, t_data *data);
void	parse_scene(t_data *data, char **tab);
void	parse_objects(t_data *data, char **tab);
// - Utils - //
t_color	parse_color(char *str);
t_vec3	parse_vec(char *str);

// --- Verif Parsing --- //
int		verif_line(char **tab);
int		verif_file_name(char *str);
int		verif_complete(t_is is);
int		verif_cylinder(char **tab);
int		verif_sphere(char **tab);
int		verif_plane(char **tab);
int		verif_al(char **tab);
int		verif_light(char **tab);
int		verif_cam(char **tab);
// - Utils - //
int		verif_n_vec(char *str);
int		verif_rgb(char *str);
int		verif_fov(char *str);
int		verif_light_ratio(char *str);
// - Syntax - //
int		verif_vec_syntax(char *str);
int		verif_rgb_syntax(char *str);

// --- Shapes --- //
t_hit	hit_sphere(t_ray ray, t_sp *sphere);
t_hit	hit_plane(t_ray ray, t_pl *plane);
t_hit	hit_cylinder(t_ray ray, t_cy *cylinder);
// - Utils - //
double	calc_t_cy(t_ray ray, t_cy *cylinder);
double	calc_t_disk(t_ray ray, t_vec3 point, t_vec3 normal);

// --- Vector Utils --- //
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_normalize(t_vec3 v);
t_vec3	vec_mult(t_vec3 v, double k);
t_vec3	vec_negate(t_vec3 vec);
t_vec3	vec_clamp(t_vec3 vec, double min, double max);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);
double	vec_length(t_vec3 v);
double	vec_dot(t_vec3 a, t_vec3 b);
double	vec_distance(t_vec3 a, t_vec3 b);

// --- Color Utils --- //
t_color	color_mix(t_color color1, t_color color2, double brightness);
t_color	color_mult(t_color color, double mult);
void	color_clamp(t_color *color);
t_color	color_add(t_color color1, t_color color2);

// --- Rays --- //
t_ray	calc_ray_cam(double sx, double sy, t_data *data);
t_ray	calc_ray(t_vec3 origin, t_vec3	goal);
t_vec3	calc_up(t_vec3 forward, t_vec3 right);
t_vec3	calc_right(t_vec3 forward, t_vec3 up);

// --- Objects ---//
void	obj_add_back(t_object **lst, t_object *new);

// --- Render --- //
void	render(t_data *data);
void	render_pixelate(t_data *data);
int		get_color(t_ray ray, t_data *data);
// - Utils - //
int		rgb_to_hex(int red, int green, int blue);
void	put_pixel(t_img *img, int x, int y, int color);
double	x_to_sx(int x, int FOV);
double	y_to_sy(int y, int FOV);
void	fill_block(t_data *data, int x, int y, int color);

// --- Controls --- //
void	set_controls(t_data *data);
void	update_pos(t_vec3 *pos, t_vec3 dir, int sign);
void	move_cam(int keycode, t_cam *cam);
void	rotate_camera_pitch(t_cam *cam, double angle);
void	rotate_camera_yaw(t_cam *cam, double angle);

// --- Exit --- //
int		ft_exit(t_data *data);

// --- Error Handling --- //
int		print_error(t_parse_error concerned, t_parse_error problem, char *str);

// --- Random Utils --- //
int		ft_strlen_until(char *str, char c);
int		is_double_in_range(double x, double min, double max);
int		is_int_in_range(int x, int min, int max);
double	double_clamp(double in, double min, double max);

#endif