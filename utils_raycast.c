/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:41:34 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:41:37 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	tex_color(t_all *all)
{
	all->rcst.texy = (int)all->rcst.texpos;
	raz1(all);
	all->rcst.texpos += all->rcst.step;
	tri1(all);
	dva1(all);
	if (all->rcst.x >= 0 && all->rcst.y >= 0)
		my_mlx_pixel_put(all, all->rcst.x +
		all->rcst.c, all->rcst.y, *(unsigned int *)all->rcst.co);
	if (all->rcst.x == all->win.x - 1)
		my_mlx_pixel_put(all, all->rcst.x,
		all->rcst.y, *(unsigned int *)all->rcst.co);
}

void	cikl_pech(t_all *all)
{
	all->rcst.y = -1;
	while (++all->rcst.y < all->win.y)
	{
		if (all->rcst.y < all->rcst.drawstart)
			my_mlx_pixel_put(all, all->rcst.x, all->rcst.y, cvet(all));
		else if (all->rcst.y >= all->rcst.drawstart
		&& all->rcst.y <= all->rcst.drawend)
			tex_color(all);
		else
			my_mlx_pixel_put(all, all->rcst.x, all->rcst.y, cvet1(all));
	}
}

void	raydire(t_all *all)
{
	double	camerax;

	camerax = 2 * all->rcst.x / (double)all->win.x - 1;
	all->rcst.rdx = all->dir.x + all->plan.planex * camerax;
	all->rcst.rdy = all->dir.y + all->plan.planey * camerax;
	if (all->rcst.rdx < 0)
	{
		all->rcst.stepx = -1;
		all->rcst.si_d_x = (all->pos.x - all->rcst.mapx) * all->rcst.ddx;
	}
	else
	{
		all->rcst.stepx = 1;
		all->rcst.si_d_x = (all->rcst.mapx + 1.0 - all->pos.x) * all->rcst.ddx;
	}
	if (all->rcst.rdy < 0)
	{
		all->rcst.stepy = -1;
		all->rcst.si_d_y = (all->pos.y - all->rcst.mapy) * all->rcst.ddy;
	}
	else
	{
		all->rcst.stepy = 1;
		all->rcst.si_d_y = (all->rcst.mapy + 1.0 - all->pos.y) * all->rcst.ddy;
	}
}

void	hit(t_all *all)
{
	all->rcst.hit = 0;
	while (all->rcst.hit == 0)
	{
		if (all->rcst.si_d_x < all->rcst.si_d_y)
		{
			all->rcst.si_d_x += all->rcst.ddx;
			all->rcst.mapx += all->rcst.stepx;
			all->rcst.side = 0;
		}
		else
		{
			all->rcst.si_d_y += all->rcst.ddy;
			all->rcst.mapy += all->rcst.stepy;
			all->rcst.side = 1;
		}
		if (AMM[all->rcst.mapy][all->rcst.mapx] == '1')
			all->rcst.hit = 1;
	}
}

void	vice(t_all *all)
{
	double	wallx;

	if (all->rcst.side == 0)
		all->rcst.pwd = (all->rcst.mapx - all->pos.x +
		(1 - all->rcst.stepx) / 2) / all->rcst.rdx;
	else
		all->rcst.pwd = (all->rcst.mapy - all->pos.y +
		(1 - all->rcst.stepy) / 2) / all->rcst.rdy;
	all->rcst.zbuffer[all->rcst.x] = all->rcst.pwd;
	all->rcst.lh = (int)(all->win.y / all->rcst.pwd);
	all->rcst.drawstart = -all->rcst.lh / 2 + all->win.y / 2;
	if (all->rcst.drawstart < 0)
		all->rcst.drawstart = 0;
	all->rcst.drawend = all->rcst.lh / 2 + all->win.y / 2;
	if (all->rcst.drawend >= all->win.y)
		all->rcst.drawend = all->win.y - 1;
	if (all->rcst.side == 0)
		wallx = all->pos.y + all->rcst.pwd * all->rcst.rdy;
	else
		wallx = all->pos.x + all->rcst.pwd * all->rcst.rdx;
	wallx -= floor((wallx));
	all->rcst.texx = (int)(wallx * (double)(all->tex.nort.witdh));
	ch4(all);
}
