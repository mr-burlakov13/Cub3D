/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_sp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 02:12:57 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/22 02:13:01 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	spr2(t_all *all)
{
	if (all->sp.s <= all->pos.count_s - 1)
		all->sp.c = -1;
	else
		all->sp.c = 0;
}

void	spr3(t_all *all)
{
	if (all->sp.texx >= all->tex.sprite.witdh - 2)
		all->sp.texx = all->tex.sprite.witdh - 3;
	if (all->sp.texx < 0)
		all->sp.texx = 0;
	all->sp.d = NMN * 256 - WY * 128 + all->sp.sht * 128;
	all->sp.texy = ((all->sp.d * ATSV) / ASS) / 256;
	if (all->sp.texy > all->tex.sprite.visota)
		all->sp.texy = all->tex.sprite.visota;
	if (all->sp.texy < 0)
		all->sp.texy = 0;
	all->sp.color1 = (unsigned int *)(all->tex.sprite.textur +
	all->tex.sprite.len * all->sp.texy + all->sp.texx
	* (all->tex.sprite.bpp / 8));
}

void	spr0(t_all *all)
{
	if (all->sp.s == all->pos.count_s - 1 && all->win.x > 299 && WY > 299)
		if ((*(unsigned int *)all->sp.color1 !=
		BLACK) && all->sp.s > 0 && NMN > 0)
			my_mlx_pixel_put(all, all->sp.s,
			NMN, *(unsigned int *)all->sp.color1);
}
