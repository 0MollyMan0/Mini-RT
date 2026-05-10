/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:52:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/05/10 10:31:51 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	print_str_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
			printf("[%s]", tab[i]);
		else
			printf(", [%s]", tab[i]);
		i++;
	}
	printf("\n");
}

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
	print_str_tab(tab);
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
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_exit(data);
	while ((line = get_next_line(fd)))
	{
		if (is_empty(line))
		{
			free(line);
			continue;
		}
		else
			process_line(line, data);
	}
	close(fd);
}
