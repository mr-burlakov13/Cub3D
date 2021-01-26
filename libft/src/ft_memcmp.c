/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:20:52 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/04 21:22:31 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ptr;
	const unsigned char *ptr2;
	size_t				i;

	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	ptr = (const unsigned char*)s1;
	ptr2 = (const unsigned char*)s2;
	while (n--)
	{
		if (ptr[i] != ptr2[i])
			return (ptr[i] - ptr2[i]);
		i++;
	}
	return (0);
}
