/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:53:55 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/15 10:56:55 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color color_mult(t_color color, double mult)
{
	color.r *= mult;
	color.g *= mult;
	color.b *= mult;
	color.hex = rgb_to_hex((int)color.r, (int)color.g, (int)color.b);
	return (color);
}
