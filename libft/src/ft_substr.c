/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:01:40 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/04 23:03:27 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	unsigned int	i;

	if (!(arr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (i <= start)
	{
		arr[0] = '\0';
		return (arr);
	}
	i = 0;
	while (len-- && s[i + start])
	{
		arr[i] = s[i + start];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
