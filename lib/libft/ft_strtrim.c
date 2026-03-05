/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 09:19:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/01/02 13:14:41 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	is_in_str(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	strcpy_trim(const char *s, char *new, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start <= end)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = '\0';
}

static size_t	calc_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (is_in_str(s1[i], set) == 1)
		i++;
	return (i);
}

static size_t	calc_end(char const *s1, char const *set, size_t start)
{
	size_t	i;

	if (start < ft_strlen(s1))
	{
		i = ft_strlen(s1) - 1;
		while (is_in_str(s1[i], set) == 1)
			i--;
		return (i);
	}
	else
		return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;
	size_t	x;

	if (!s1)
		return (NULL);
	start = calc_start(s1, set);
	end = calc_end(s1, set, start);
	if (end == start && start == ft_strlen(s1))
		x = 1;
	else
		x = 2;
	new = malloc(sizeof(char) * (end - start + x));
	if (!new)
		return (NULL);
	strcpy_trim(s1, new, start, end);
	return (new);
}
