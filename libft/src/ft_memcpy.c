/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:22:45 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/04 21:27:24 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *b, void *mas, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;
	int					i;

	i = 0;
	if (mas == NULL && b == NULL)
		return (NULL);
	ptr = (unsigned char*)b;
	ptr2 = (unsigned char*)mas;
	while (len--)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (b);
}
