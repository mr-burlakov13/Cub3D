/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:42:15 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:42:23 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	valid_igrok(t_all *all, int fd)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (AMM[++i])
	{
		j = -1;
		while (AMM[i][++j])
			if (ft_strchr1(SYM_PLAYER, AMM[i][j]))
			{
				count++;
				route(AMM[i][j], all);
			}
	}
	if (count != 1)
		ex_clz(fd);
}

void	valid_krug(t_all *all, int fd)
{
	size_t i;
	size_t j;

	i = -1;
	while (AMM[++i])
	{
		j = -1;
		while (AMM[i][++j])
			if (ft_strchr1(MAP_SYM, AMM[i][j]))
			{
				if (AMM[i][j + 1] == '\0' || AMM[i][j + 1] == ' '
					|| AMM[i][j - 1] == ' '
					|| AMM[i - 1][j - 1] == ' ' || AMM[i - 1][j] == '\0'
					|| AMM[i - 1][j] == ' '
					|| AMM[i - 1][j + 1] == '\0' || AMM[i - 1][j + 1] == ' '
					|| AMM[i + 1][j - 1] == ' '
					|| AMM[i + 1][j] == '\0' || AMM[i + 1][j] == ' '
					|| AMM[i + 1][j + 1] == '\0' || AMM[i + 1][j + 1] == ' ')
					ex_clz(fd);
				if (ft_strlen(AMM[i - 1]) < j || ft_strlen(AMM[i + 1]) < j)
					ex_clz(fd);
			}
	}
}

void	valid_perim(t_all *all, int nb, int fd)
{
	int i;

	i = -1;
	while (AMM[0][++i])
		if (AMM[0][i] != '1' && AMM[0][i] != ' ')
			ex_clz(fd);
	i = -1;
	while (AMM[nb - 1][++i])
		if (AMM[nb - 1][i] != '1' && AMM[nb - 1][i] != ' ')
			ex_clz(fd);
	i = -1;
	while (AMM[++i])
		if (AMM[i][0] != '1' && AMM[i][0] != ' ')
			ex_clz(fd);
}
