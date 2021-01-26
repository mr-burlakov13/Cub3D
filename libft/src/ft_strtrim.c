/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:58:57 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/07 19:38:52 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t n;
	size_t q;
	size_t s;

	if (!s1)
		return (NULL);
	n = 0;
	q = 0;
	s = ft_strlen(s1);
	while (s1[n] && ft_strchr(set, s1[n]))
		n++;
	if (n == s)
		return (ft_substr("", 0, 1));
	while (ft_strrchr(set, s1[s - q - 1]))
		q++;
	return (ft_substr(s1, n, (s - n - q)));
}