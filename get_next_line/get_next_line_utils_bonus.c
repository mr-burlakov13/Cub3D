/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:20:51 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/19 20:20:59 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin1(char *s1, const char *s2)
{
	int		i;
	int		j;
	int		len_1;
	int		len_2;
	char	*arr;

	len_1 = ft_strlen1(s1);
	len_2 = ft_strlen1(s2);
	i = 0;
	j = 0;
	if (!(arr = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1))))
		return (NULL);
	while (len_1--)
	{
		arr[i] = s1[i];
		i++;
	}
	while (len_2--)
		arr[i++] = s2[j++];
	arr[i] = '\0';
	free(s1);
	return (arr);
}

char	*ft_strchr1(const char *s, int c)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		s = &s[i + 1];
	}
	return ((char *)s);
}

size_t	ft_strlen1(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_mod(char *s1)
{
	int		i;
	char	*arr;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\n' && s1[i] != '\0')
		i++;
	arr = (char*)malloc(sizeof(char) * (i + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
