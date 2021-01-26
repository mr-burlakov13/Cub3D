/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:43:37 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:43:39 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	st_8_4(t_all *all, char *line, int fd)
{
	char	*str;
	char	**mas;

	all->st_8.c += 1;
	str = ft_strtrim(&line[1], " ");
	mas = ft_split(str, ',');
	free(str);
	if (mas[3] != NULL)
		ex_clz(fd);
	all->potolok.a = get_nb(mas[0], fd);
	all->potolok.b = get_nb(mas[1], fd);
	all->potolok.c = get_nb(mas[2], fd);
	free1(mas);
}

void	st_8_3(t_all *all, char *line, int fd)
{
	char	*str;
	char	**mas;

	all->st_8.f += 1;
	str = ft_strtrim(&line[1], " ");
	mas = ft_split(str, ',');
	free(str);
	if (mas[3] != NULL)
		ex_clz(fd);
	all->pol.a = get_nb(mas[0], fd);
	all->pol.b = get_nb(mas[1], fd);
	all->pol.c = get_nb(mas[2], fd);
	free1(mas);
}

void	st_8_2(t_all *all, char *line, int fd)
{
	char	*str;
	char	**mas;
	int		a;
	int		b;

	if (line[0] == 'R' && line[1] == ' ')
	{
		all->st_8.r += 1;
		str = ft_strtrim(&line[1], " ");
		mas = ft_split(str, ' ');
		free(str);
		if (mas[2] != NULL)
			ex_clz(fd);
		a = get_nb2(mas[0], fd);
		b = get_nb2(mas[1], fd);
		rezult_r(a, b, all, fd);
		free1(mas);
	}
	else if (line[0] == 'F' && line[1] == ' ')
		st_8_3(all, line, fd);
	else if (line[0] == 'C' && line[1] == ' ')
		st_8_4(all, line, fd);
}

void	st_8_1(t_all *all, char *line, int fd)
{
	char	*str;

	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		all->st_8.ea += 1;
		str = ft_strtrim(&line[2], " ");
		eror11(str, fd);
		all->tex.east.name = str;
	}
	else if (line[0] == 'S' && line[1] == ' ')
	{
		all->st_8.s += 1;
		str = ft_strtrim(&line[1], " ");
		eror11(str, fd);
		all->tex.sprite.name = str;
	}
	else
		st_8_2(all, line, fd);
}

void	st_8(t_all *all, char *line, int fd)
{
	char	*str;

	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		all->st_8.no += 1;
		str = ft_strtrim(&line[2], " ");
		eror11(str, fd);
		all->tex.nort.name = str;
	}
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		all->st_8.so += 1;
		str = ft_strtrim(&line[2], " ");
		eror11(str, fd);
		all->tex.south.name = str;
	}
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		all->st_8.we += 1;
		str = ft_strtrim(&line[2], " ");
		eror11(str, fd);
		all->tex.west.name = str;
	}
	else
		st_8_1(all, line, fd);
}
