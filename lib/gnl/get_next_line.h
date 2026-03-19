/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:42:22 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/05 15:07:52 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*gnl_substr(char *s, int start);
int		gnl_strchr_i(char *s, char c);
char	*gnl_extract(char *s, int end);
char	*gnl_minijoin(char *s1, char *s2);
int		gnl_strlen(char *s);

#endif