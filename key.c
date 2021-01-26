/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:42:43 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:42:46 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	alk(t_all *all)
{
	if (all->flagi.a == 1)
	{
		if (A1 != '1' && A2 != '2')
			all->pos.x -= all->plan.planex * SPEED;
		if (A2 != '1' && A2 != '2')
			all->pos.y -= all->plan.planey * SPEED;
	}
	if (all->flagi.k == 1)
	{
		all->dir.a = all->dir.x;
		all->dir.x = all->dir.x * cos(-SPEED) - all->dir.y * sin(-SPEED);
		all->dir.y = all->dir.a * sin(-SPEED) + all->dir.y * cos(-SPEED);
		all->dir.b = all->plan.planex;
		all->plan.planex = APPX;
		all->plan.planey = AAPX3;
	}
	if (all->flagi.l == 1)
	{
		all->dir.a = all->dir.x;
		all->dir.x = all->dir.x * cos(SPEED) - all->dir.y * sin(SPEED);
		all->dir.y = all->dir.a * sin(SPEED) + all->dir.y * cos(SPEED);
		all->dir.b = all->plan.planex;
		all->plan.planex = APPX2;
		all->plan.planey = AAPX4;
	}
}

int		escape(t_all *all)
{
	(void)all;
	exit(0);
	return (1);
}

int		key_press_finish(t_all *all)
{
	if (all->flagi.w == 1)
	{
		if (W1 != '1' && W1 != '2')
			all->pos.y += all->dir.y * SPEED;
		if (W2 != '1' && W2 != '2')
			all->pos.x += all->dir.x * SPEED;
	}
	if (all->flagi.s == 1)
	{
		if (S1 != '1' && S1 != '2')
			all->pos.y -= all->dir.y * SPEED;
		if (S2 != '1' && S2 != '2')
			all->pos.x -= all->dir.x * SPEED;
	}
	if (all->flagi.d == 1)
	{
		if (D1 != '1' && D1 != '2')
			all->pos.x += all->plan.planex * SPEED;
		if (D2 != '1' && D2 != '2')
			all->pos.y += all->plan.planey * SPEED;
	}
	alk(all);
	picture(all);
	return (0);
}

int		key_un_press(int key, t_all *all)
{
	if (key == W || key == UP)
		all->flagi.w = 0;
	else if (key == A)
		all->flagi.a = 0;
	else if (key == S || key == DOWN)
		all->flagi.s = 0;
	else if (key == D)
		all->flagi.d = 0;
	else if (key == LEFT)
		all->flagi.l = 0;
	else if (key == RIGHT)
		all->flagi.k = 0;
	return (0);
}

int		key_press(int key, t_all *all)
{
	if (key == ESC)
		escape(all);
	else if (key == W || key == UP)
		all->flagi.w = 1;
	else if (key == A)
		all->flagi.a = 1;
	else if (key == S || key == DOWN)
		all->flagi.s = 1;
	else if (key == D)
		all->flagi.d = 1;
	else if (key == LEFT)
		all->flagi.l = 1;
	else if (key == RIGHT)
		all->flagi.k = 1;
	return (0);
}
