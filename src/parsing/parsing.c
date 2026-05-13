/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:52:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/13 08:39:46 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	process_line(char *line, t_data *data)
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
	data->parsing.fd = open(name, O_RDONLY);
	if (data->parsing.fd < 0 || !verif_file_name(name))
		ft_exit(data);
	data->is.fd_open = 1;
	data->parsing.line = " ";
	while (data->parsing.line)
	{
		data->parsing.line = get_next_line(data->parsing.fd);
		if (!data->parsing.line)
			break ;
		if (!is_empty(data->parsing.line))
			process_line(data->parsing.line, data);
		else
			free(data->parsing.line);
	}
	if (!verif_complete(data->is))
		ft_exit(data);
	close(data->parsing.fd);
	data->is.fd_open = 0;
}
