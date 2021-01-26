/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eror.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:43:47 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:43:49 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	ex_clz(int fd)
{
	write(1, "erorr", 5);
	close(fd);
	exit(0);
}

void	start_ex(void)
{
	write(1, "erorr", 5);
	exit(0);
}

void	free1(char **s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

int		konec(t_all *all, int win)
{
	int	i;

	i = 0;
	while (i < all->map.y)
		free(all->map.mapa[i++]);
	if (win == 1)
		mlx_destroy_window(all->mlx.ptr, all->win.ptr);
	free(all->mlx.ptr);
	exit(0);
	return (1);
}

void	eror11(char *str, int fd)
{
	if (-1 == open(str, O_RDONLY))
		ex_clz(fd);
}
