/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 09:19:48 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/08 07:33:24 by anfouger         ###   ########.fr       */
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
		++i;
	}
	new[i] = '\0';
}

static size_t	calc_start(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (is_in_str(s[i], set) == 1)
		++i;
	return (i);
}

static size_t	calc_end(char const *s, char const *set, size_t start)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	if (start < len)
	{
		i = len - 1;
		while (is_in_str(s[i], set) == 1)
			--i;
		return (i);
	}
	else
		return (start);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len_new;
	char	*new;

	if (!s || !set)
		return (NULL);
	start = calc_start(s, set);
	end = calc_end(s, set, start);
	if (end == start && start == ft_strlen(s))
		len_new = end - start + 1;
	else
		len_new = end - start + 2;
	new = malloc(sizeof(char) * (len_new));
	if (!new)
		return (NULL);
	strcpy_trim(s, new, start, end);
	return (new);
}
