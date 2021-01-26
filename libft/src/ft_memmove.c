/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:27:36 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/04 21:30:01 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;
	size_t				i;
	size_t				j;

	i = 0;
	j = 0;
	ptr = (unsigned char*)dst;
	ptr2 = (unsigned const char*)src;
	if (src == dst)
		return (dst);
	if (ptr2 < ptr)
		while (++i <= len)
			ptr[len - i] = ptr2[len - i];
	else
		while (len--)
		{
			ptr[j] = ptr2[j];
			j++;
		}
	return (dst);
}
