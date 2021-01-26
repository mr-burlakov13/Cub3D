/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvet.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:43:17 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:43:19 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	prov1(t_all *all, int fd)
{
	if (all->st_8.count != 8)
		ex_clz(fd);
	if (S8.no != 1 || S8.so != 1 || S8.we != 1 || S8.ea != 1
		|| S8.s != 1 || S8.r != 1 || S8.f != 1 || S8.c != 1)
		ex_clz(fd);
}

int		cvet1(t_all *all)
{
	int cv;

	cv = all->pol.a;
	cv = (cv << 8) + all->pol.b;
	cv = (cv << 8) + all->pol.c;
	return (cv);
}

int		cvet(t_all *all)
{
	int cv;

	cv = all->potolok.a;
	cv = (cv << 8) + all->potolok.b;
	cv = (cv << 8) + all->potolok.c;
	return (cv);
}

int		get_nb2(char *str, int fd)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		if (j > 100000)
		{
			i++;
			continue;
		}
		j = j * 10 + str[i++] - '0';
	}
	if (str[i] != '\0')
		ex_clz(fd);
	return (j);
}

int		get_nb(char *line, int fd)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
	{
		j = j * 10 + line[i++] - '0';
		if (j > 10000)
			ex_clz(fd);
	}
	while (line[i])
	{
		if (line[i] != ' ')
			ex_clz(fd);
		i++;
	}
	if (j < 0 || j > 255)
		ex_clz(fd);
	return (j);
}
