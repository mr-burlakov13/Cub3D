/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:47:50 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/04 21:14:32 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_itoa(long nb)
{
	int i;

	i = 0;
	if (nb <= 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
static void	ft_itoa_zanos(char *mas, int n, int *i)
{
	unsigned int m;

	m = n;
	if (n < 0)
	{
		mas[*i] = '-';
		*i = *i + 1;
		m = -n;
	}
	if (m > 9)
	{
		ft_itoa_zanos(mas, m / 10, i);
		ft_itoa_zanos(mas, m % 10, i);
	}
	if (m < 10)
	{
		mas[*i] = m + '0';
		*i = (*i) + 1;
	}
}

char		*ft_itoa(int n)
{
	char	*mas;
	int		*i;
	int		k;

	i = &k;
	k = 0;
	mas = (char*)malloc(sizeof(char) * (ft_len_itoa(n) + 1));
	if (mas)
	{
		ft_itoa_zanos(mas, n, i);
		mas[k] = '\0';
	}
	return (mas);
}
