/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:52:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/04/27 14:14:12 by anfouger         ###   ########.fr       */
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

int	verif_line(char **tab)
{
	
	return (0);
}

static int process_line(char *line, t_data *data)
{
	char	**tab;
	char	*tmp;
	int		res;

	tmp = ft_strtrim(line, "\n");
	free(line);
	line = tmp;
	tab = ft_split(line, ' ');
	free(line);
	print_str_tab(tab);
	if (verif_line(tab))
		ft_exit(data);
	if (!ft_strcmp(tab[0], "sp") || !ft_strcmp(tab[0], "pl")
		|| !ft_strcmp(tab[0], "cy"))
		res = parse_objects(data, tab);
	else if (!ft_strcmp(tab[0], "A") || !ft_strcmp(tab[0], "C")
		|| !ft_strcmp(tab[0], "L"))
		res = parse_scene(data, tab);
	else
		res = 0;
	free_str_tab(tab);
	return (res);
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
		else if (!process_line(line, data))
			ft_exit(data);
	}
	close(fd);
}
