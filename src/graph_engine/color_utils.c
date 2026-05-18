/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:53:55 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/18 09:22:33 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_color	color_inter_mult(t_color *color1, t_color *color2)
{
	t_color	result;

	result.r = color1->r * color2->r;
	result.g = color1->g * color2->g;
	result.b = color1->b * color2->b;
	result.hex = rgb_to_hex((int)result.r, (int)result.g, (int)result.b);
	return (result);
}

void	color_mult(t_color *color, double mult)
{
	color->r *= mult;
	color->g *= mult;
	color->b *= mult;
	color->hex = rgb_to_hex((int)color->r, (int)color->g, (int)color->b);
}

static void	color_div(t_color *color, double div)
{
	color->r /= div;
	color->g /= div;
	color->b /= div;
	color->hex = rgb_to_hex((int)color->r, (int)color->g, (int)color->b);
}

static void	color_clamp(t_color *color)
{
	color->r = double_clamp(color->r, 0, 255);
	color->g = double_clamp(color->g, 0, 255);
	color->b = double_clamp(color->b, 0, 255);
	color->hex = rgb_to_hex((int)color->r, (int)color->g, (int)color->b);
}

t_color	color_mix(t_color *color1, t_color *color2, double brightness)
{
	t_color	result;

	color_div(color1, 255);
	color_div(color2, 255);
	result = color_inter_mult(color1, color2);
	color_mult(&result, brightness);
	color_mult(&result, 255);
	color_clamp(&result);
	return (result);
}
