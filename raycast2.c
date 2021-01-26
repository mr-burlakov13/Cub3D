/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:36:43 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:45:43 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	route2(char c, t_all *all)
{
	if (c == 'W')
	{
		all->plan.planex = 0;
		all->plan.planey = 0.66;
		all->dir.x = -1;
		all->dir.y = 0;
	}
	else
	{
		all->plan.planex = 0;
		all->plan.planey = -0.66;
		all->dir.x = 1;
		all->dir.y = 0;
	}
}

void	route(char c, t_all *all)
{
	if (c == 'N')
	{
		all->plan.planex = -0.66;
		all->plan.planey = 0;
		all->dir.x = 0;
		all->dir.y = -1;
	}
	else if (c == 'S')
	{
		all->plan.planex = 0.66;
		all->plan.planey = 0;
		all->dir.x = 0;
		all->dir.y = 1;
	}
	else
		route2(c, all);
}

void	raycast(t_all *all)
{
	if (all->rcst.zbuffer)
		free(all->rcst.zbuffer);
	all->rcst.zbuffer = (double *)malloc(sizeof(double) * all->win.x + 1);
	all->rcst.x = -1;
	while (++all->rcst.x < all->win.x)
	{
		all->rcst.mapx = (int)all->pos.x;
		all->rcst.mapy = (int)all->pos.y;
		all->rcst.ddx = sqrt(1 + (all->rcst.rdy * all->rcst.rdy)
		/ (all->rcst.rdx * all->rcst.rdx));
		all->rcst.ddy = sqrt(1 + (all->rcst.rdx * all->rcst.rdx)
		/ (all->rcst.rdy * all->rcst.rdy));
		raydire(all);
		hit(all);
		vice(all);
		if (all->rcst.side == 0 && all->rcst.rdx > 0)
			all->rcst.texx = all->tex.nort.witdh - all->rcst.texx - 1;
		if (all->rcst.side == 1 && all->rcst.rdy < 0)
			all->rcst.texx = all->tex.nort.witdh - all->rcst.texx - 1;
		all->rcst.step = 1.0 * all->tex.nort.visota / all->rcst.lh;
		all->rcst.texpos = (all->rcst.drawstart
		- all->win.y / 2 + all->rcst.lh / 2) * all->rcst.step;
		cikl_pech(all);
	}
}
