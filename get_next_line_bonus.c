/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:20:31 by estoffel          #+#    #+#             */
/*   Updated: 2021/07/26 21:43:32 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_line(char *stock)
{
	char	*line;
	size_t	i;

	if (!stock)
		return (NULL);
	i = nl_len(stock);
	if (i == 0)
		return (NULL);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		++i;
	}
	if (stock[i] == '\n')
	{
		line[i] = stock[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *stock)
{
	char	*rest;
	size_t	i;
	size_t	j;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		++i;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!rest)
		return (NULL);
	++i;
	j = 0;
	while (stock && stock[i])
		rest[j++] = stock[i++];
	rest[j] = '\0';
	free(stock);
	return (rest);
}

char	*get_next_line(int fd)
{
	ssize_t		opt;
	char		*buf;
	char		*line;
	static char	*stock[256];

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	opt = 1;
	while (!check_nl(stock[fd]) && opt != 0)
	{
		opt = read(fd, buf, BUFFER_SIZE);
		if (opt < 0)
		{
			free(buf);
			return (NULL);
		}
		stock[fd] = ft_strjoin(stock[fd], buf, opt);
	}
	free(buf);
	line = get_line(stock[fd]);
	stock[fd] = get_rest(stock[fd]);
	return (line);
}
