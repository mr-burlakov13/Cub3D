/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:17:25 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/19 20:18:55 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);
char	*ft_strjoin1(char *s1, const char *s2);
char	*ft_strdup_mod(char *s1);
char	*ft_strchr1(const char *s, int c);
size_t	ft_strlen1(const char *s);

#endif
