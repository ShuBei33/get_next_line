/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:03:41 by estoffel          #+#    #+#             */
/*   Updated: 2021/07/26 19:43:24 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		++i;
	return (i);
}

size_t	nl_len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		++i;
	if (s[i] == '\n')
		++i;
	return (i);
}

int	check_nl(char *stock)
{
	int	i;

	i = 0;
	if (!stock)
		return (0);
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t opt)
{
	char	*output;
	int		len;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	s2[opt] = '\0';
	len = ft_strlen(s1) + ft_strlen(s2);
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		output[i] = s1[i];
		++i;
	}
	j = -1;
	while (s2 && s2[++j])
		output[i + j] = s2[j];
	output[i + j] = '\0';
	free(s1);
	return (output);
}
