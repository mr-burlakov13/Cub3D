/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zashita.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:44:39 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/22 01:44:43 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	raz1(t_all *all)
{
	if (all->rcst.texy >= all->tex.nort.visota)
		all->rcst.texy = all->tex.nort.witdh - 1;
	if (all->rcst.texy < 0)
		all->rcst.texy = 0;
}

void	dva1(t_all *all)
{
	if (all->rcst.x <= all->win.x - 1)
		all->rcst.c = -1;
	else
		all->rcst.c = 0;
}

void	tri1(t_all *all)
{
	if (all->rcst.side == 1)
	{
		if (all->rcst.stepy < 0)
			all->rcst.co = (unsigned int *)(all->tex.nort.textur
			+ all->tex.nort.len
			* all->rcst.texy + all->rcst.texx * (all->tex.nort.bpp / 8));
		else
			all->rcst.co = (unsigned int *)(all->tex.west.textur
			+ all->tex.west.len
			* all->rcst.texy + all->rcst.texx * (all->tex.west.bpp / 8));
	}
	else
	{
		if (all->rcst.stepx < 0)
			all->rcst.co = (unsigned int *)(all->tex.south.textur
			+ all->tex.south.len
				* all->rcst.texy + all->rcst.texx * (all->tex.south.bpp / 8));
		else
			all->rcst.co = (unsigned int *)(all->tex.east.textur +
			all->tex.east.len
			* all->rcst.texy + all->rcst.texx * (all->tex.east.bpp / 8));
	}
}

void	ch4(t_all *all)
{
	if (all->rcst.texx >= all->tex.nort.witdh)
		all->rcst.texx = all->tex.nort.witdh - 1;
	if (all->rcst.texx < 0)
		all->rcst.texx = 0;
}
