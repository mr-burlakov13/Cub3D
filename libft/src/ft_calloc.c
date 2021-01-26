/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:24:51 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/22 17:13:31 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*m;

	i = 0;
	m = (void*)malloc(count * size);
	if (m == NULL)
		return (NULL);
	while (i < count * size)
	{
		m[i] = 0;
		i++;
	}
	return (m);
}
