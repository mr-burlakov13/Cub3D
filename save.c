/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:42:05 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:42:07 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

static void			transfer(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static	void		bmp_hdr(t_all *all, int file_size, int fd)
{
	unsigned char btr[54];

	ft_bzero(btr, 54);
	btr[0] = (unsigned char)('B');
	btr[1] = (unsigned char)('M');
	transfer(file_size, btr + 2);
	btr[10] = (unsigned char)(54);
	btr[14] = (unsigned char)(40);
	transfer(all->win.x, btr + 18);
	transfer(all->win.y, btr + 22);
	btr[26] = (unsigned char)(1);
	btr[28] = (unsigned char)(24);
	write(fd, btr, 54);
}

static	void		get_pxl(t_all *all, int fd)
{
	int	i;
	int	j;
	int	cvet;

	i = all->win.y - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < all->win.x)
		{
			cvet = *(int*)(all->img.adr +
			(i * all->img.size_len + j * (all->img.bi_p_p / 8)));
			write(fd, &cvet, 3);
		}
		i--;
	}
}

void				save(t_all *all)
{
	int	fd;
	int	limb;

	picture(all);
	while (all->win.x % 4 != 0)
		all->win.x--;
	limb = 54 + (4 * all->win.y * all->win.x);
	if (!(fd = open("screen.bmp", O_WRONLY | O_CREAT
	| O_TRUNC | O_APPEND, 0666)))
		ex_clz(all->pars.fd);
	bmp_hdr(all, limb, fd);
	get_pxl(all, fd);
	close(fd);
	exit(0);
}
