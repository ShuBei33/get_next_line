/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:03:51 by estoffel          #+#    #+#             */
/*   Updated: 2021/07/26 21:16:31 by estoffel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <string.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2, ssize_t opt);
char	*get_next_line(int fd);

int		check_nl(char *stock);

size_t	ft_strlen(char *s);
size_t	nl_len(char *s);

#endif
