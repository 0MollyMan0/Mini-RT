/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:52:04 by anfouger          #+#    #+#             */
/*   Updated: 2026/03/24 08:56:29 by anfouger         ###   ########.fr       */
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

static int process_line(char *line, t_data *data)
{
	(void)data;
	char **tab;
	
	line = ft_strtrim(line, "\n");
	tab = ft_split(line, ' ');
	print_str_tab(tab);
	free(tab);
	return (0);
}

void	parse_file(char *name, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_exit(data, 0);
	while ((line = get_next_line(fd)))
	{
		if (is_empty(line))
		{
			free(line);
			continue;
		}
		if (!process_line(line, data))
			ft_exit(data, 1);
		free(line);
	}
	close(fd);
}
