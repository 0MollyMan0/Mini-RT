/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:52:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/11 14:35:59 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void process_line(char *line, t_data *data)
{
	char	**tab;
	char	*tmp;

	tmp = ft_strtrim(line, "\n");
	free(line);
	line = tmp;
	tab = ft_split(line, ' ');
	free(line);
	if (!verif_line(tab))
	{
		free_str_tab(tab);
		ft_exit(data);
	}
	if (!ft_strcmp(tab[0], "sp") || !ft_strcmp(tab[0], "pl")
		|| !ft_strcmp(tab[0], "cy"))
		parse_objects(data, tab);
	else if (!ft_strcmp(tab[0], "A") || !ft_strcmp(tab[0], "C")
		|| !ft_strcmp(tab[0], "L"))
		parse_scene(data, tab);
	free_str_tab(tab);
}

void	parse_file(char *name, t_data *data)
{
	char	*line;

	data->fd = open(name, O_RDONLY);
	data->is_fd_open = 1;
	if (data->fd < 0 || !verif_name_file(name))
		ft_exit(data);
	while ((line = get_next_line(data->fd)))
	{
		if (is_empty(line))
		{
			free(line);
			continue;
		}
		else
			process_line(line, data);
	}
	close(data->fd);
	data->is_fd_open = 0;
}
