/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:04:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/05 11:53:52 by anfouger         ###   ########.fr       */
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
# define WIN_HEIGHT 600

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


// --- MLX --- //
t_mlx *init_mlx(void);

// --- Render --- //
void	render(t_mlx *mlx);
void	put_pixel(t_img *img, int x, int y, int color);

#endif