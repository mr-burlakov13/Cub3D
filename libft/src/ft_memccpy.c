/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:41:28 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/04 20:43:38 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *b, const void *mas, int c, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;
	size_t				i;

	i = 0;
	ptr = (unsigned char*)b;
	ptr2 = (unsigned const char*)mas;
	while (len--)
	{
		ptr[i] = ptr2[i];
		if (ptr2[i] == (unsigned char)c)
			return (&ptr[i + 1]);
		i++;
	}
	return (NULL);
}
