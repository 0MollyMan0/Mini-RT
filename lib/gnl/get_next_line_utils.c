/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:42:02 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/05 15:07:34 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_extract(char *s, int end)
{
	int		x;
	char	*sub;

	if (!s || s[0] == '\0')
		return (NULL);
	sub = malloc(end + 2);
	if (!sub)
	{
		return (NULL);
	}
	x = 0;
	while (x <= end)
	{
		sub[x] = s[x];
		x++;
	}
	sub[x] = '\0';
	return (sub);
}
int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	gnl_strchr_i(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_minijoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	s1 = NULL;
	return (new);
}

char	*gnl_substr(char *s, int start)
{
	char	*sub;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= gnl_strlen(s))
	{
		free(s);
		return (NULL);
	}
	sub = malloc(gnl_strlen(s) - start + 1);
	if (!sub)
		return (NULL);
	while (s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	free(s);
	s = NULL;
	return (sub);
}
