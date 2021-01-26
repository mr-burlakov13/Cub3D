/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:38:16 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/04 22:44:20 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*arr;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (arr == NULL)
		return (NULL);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		arr[i] = s2[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	return (arr);
}
