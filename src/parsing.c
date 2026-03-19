/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:52:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/19 11:46:36 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	process_line(char *line)
{
	(void)line;
}

void	parse_file(char *name, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_exit(data);
	while ((line = get_next_line(fd)))
	{
		if (is_empty(line))
			continue;
		process_line(line);
	}
}
