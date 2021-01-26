/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:43:28 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:43:30 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	prs5(t_all *all)
{
	if (all->pars.line[0] == '\0' && all->flagi.pt == 1)
		ex_clz(all->pars.fd);
}

void	prs6(t_all *all)
{
	if (all->st_8.count == 8)
		all->flagi.pt = 1;
}

void	prs7(t_all *all)
{
	if (!(ft_strchr1(MAP_8_ST, APL)) && all->flagi.pt == 0)
		ex_clz(all->pars.fd);
}

void	prs8(t_all *all)
{
	st_8(all, all->pars.line, all->pars.fd);
	all->st_8.count += 1;
	free(all->pars.line);
}

void	prs9(t_all *all)
{
	if (all->flagi.pt == 1)
		ggvp(all, all->pars.line, all->pars.fd);
}
