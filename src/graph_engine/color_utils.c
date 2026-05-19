/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:53:55 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/19 09:10:19 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_color	color_inter_mult(t_color color1, t_color color2)
{
	t_color	result;

	result.r = color1.r * color2.r;
	result.g = color1.g * color2.g;
	result.b = color1.b * color2.b;
	result.hex = rgb_to_hex((int)result.r, (int)result.g, (int)result.b);
	return (result);
}

t_color	color_mult(t_color color, double mult)
{
	t_color	result;

	result.r = color.r * mult;
	result.g = color.g * mult;
	result.b = color.b * mult;
	result.hex = rgb_to_hex((int)color.r, (int)color.g, (int)color.b);
	color_clamp(&result);
	return (result);
}

static t_color	color_div(t_color color, double div)
{
	t_color	result;

	result.r = color.r / div;
	result.g = color.g / div;
	result.b = color.b / div;
	result.hex = rgb_to_hex((int)color.r, (int)color.g, (int)color.b);
	color_clamp(&result);
	return (result);
}

void	color_clamp(t_color *color)
{
	color->r = double_clamp(color->r, 0, 255);
	color->g = double_clamp(color->g, 0, 255);
	color->b = double_clamp(color->b, 0, 255);
	color->hex = rgb_to_hex((int)color->r, (int)color->g, (int)color->b);
}

t_color	color_mix(t_color color1, t_color color2, double brightness)
{
	t_color	result;

	color1 = color_div(color1, 255);
	color2 = color_div(color2, 255);
	result = color_inter_mult(color1, color2);
	result = color_mult(result, brightness);
	result = color_mult(result, 255);
	color_clamp(&result);
	return (result);
}
