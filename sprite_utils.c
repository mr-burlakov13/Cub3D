/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:43:06 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:43:08 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

static void	draw_sp(t_all *all)
{
	all->sp.s = all->sp.dsx - 1;
	while (++all->sp.s < all->sp.dex)
	{
		all->sp.texx = (int)((256 * (all->sp.s -
		(-all->sp.swh / 2 + all->sp.ssx))
		* all->tex.sprite.witdh / all->sp.swh) / 256);
		if (all->sp.tryy > 0 && all->sp.s > 0 && all->sp.s < all->win.x
		&& all->sp.tryy < all->rcst.zbuffer[all->sp.s])
		{
			NMN = all->sp.dsy - 1;
			while (++NMN < all->sp.dey)
			{
				spr2(all);
				spr3(all);
				if ((*(unsigned int *)all->sp.color1 !=
				BLACK) && all->sp.s > 0 && NMN > 0)
					my_mlx_pixel_put(all, all->sp.s + all->sp.c,
					NMN, *(unsigned int *)all->sp.color1);
				spr0(all);
			}
		}
	}
}

static void	zzzw(t_all *all)
{
	all->sp.ivt = 1.0 / (all->plan.planex * all->dir.y
	- all->dir.x * all->plan.planey);
	all->sp.trx = all->sp.ivt * (all->dir.y * all->sp.spx
	- all->dir.x * all->sp.spy);
	all->sp.tryy = all->sp.ivt * (-all->plan.planey
	* all->sp.spx + all->plan.planex * all->sp.spy);
	all->sp.ssx = (int)((all->win.x / 2) * (1 + all->sp.trx / all->sp.tryy));
	all->sp.sht = abs((int)(WY / (all->sp.tryy)));
	all->sp.dsy = -all->sp.sht / 2 + WY / 2;
	if (all->sp.dsy < 0)
		all->sp.dsy = 0;
	all->sp.dey = all->sp.sht / 2 + WY / 2;
	if (all->sp.dey >= WY)
		all->sp.dey = WY - 1;
	if (all->win.x > WY)
		all->sp.swh = abs((int)(WY / (all->sp.tryy) * (all->win.x / WY)));
	else
		all->sp.swh = abs((int)(WY / (all->sp.tryy) / (WY / all->win.x)));
	all->sp.dsx = -all->sp.swh / 2 + all->sp.ssx;
	if (all->sp.dsx < 0)
		all->sp.dsx = 0;
	all->sp.dex = all->sp.swh / 2 + all->sp.ssx;
	if (all->sp.dex >= all->win.x)
		all->sp.dex = all->win.x - 1;
}

static void	sort_sprite(t_all *all)
{
	int		i;
	int		j;
	float	swap;

	i = 1;
	while (i < all->pos.count_s)
	{
		j = i;
		while ((int)all->spr[j].d > (int)all->spr[j - 1].d && j != 0)
		{
			swap = all->spr[j].d;
			all->spr[j].d = all->spr[j - 1].d;
			all->spr[j - 1].d = swap;
			swap = all->spr[j].x;
			all->spr[j].x = all->spr[j - 1].x;
			all->spr[j - 1].x = swap;
			swap = all->spr[j].y;
			all->spr[j].y = all->spr[j - 1].y;
			all->spr[j - 1].y = swap;
			j -= 1;
		}
		i++;
	}
}

void		sprite(t_all *all)
{
	int k;

	k = -1;
	while (++k < all->pos.count_s)
		all->spr[k].d = BOD;
	sort_sprite(all);
	k = -1;
	while (++k < all->pos.count_s)
	{
		all->sp.spx = all->spr[k].x - all->pos.x;
		all->sp.spy = all->spr[k].y - all->pos.y;
		zzzw(all);
		draw_sp(all);
	}
}
