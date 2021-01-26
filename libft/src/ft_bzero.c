/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:21:08 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/04 23:04:58 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	ptr = (unsigned char*)b;
	while (len--)
		ptr[i++] = 0;
	return ((void)(b));
}
