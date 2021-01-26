/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:42:34 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:42:37 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void			picture(t_all *all)
{
	raycast(all);
	sprite(all);
	mlx_put_image_to_window(all->mlx.ptr, all->win.ptr, all->img.ptr, 0, 0);
}

int				job_map(t_all *all)
{
	all->mlx.ptr = mlx_init();
	pars1(all);
	sprite_mas(all);
	all->win.ptr = mlx_new_window(all->mlx.ptr,
	all->win.x, all->win.y, "cub3D");
	new_pict(all);
	if (all->flagi.arg == 3)
		save(all);
	picture(all);
	mlx_hook(all->win.ptr, 2, 0, &key_press, all);
	mlx_hook(all->win.ptr, 3, 0, &key_un_press, all);
	mlx_hook(all->win.ptr, 17, 0L, &escape, all);
	mlx_loop_hook(all->mlx.ptr, &key_press_finish, all);
	mlx_loop(all->mlx.ptr);
	return (1);
}

void			initialization2(t_all *all)
{
	all->st_8.r = 0;
	all->st_8.no = 0;
	all->st_8.so = 0;
	all->st_8.we = 0;
	all->st_8.ea = 0;
	all->st_8.s = 0;
	all->st_8.f = 0;
	all->st_8.c = 0;
	all->st_8.count = 0;
	all->flagi.w = 0;
	all->flagi.s = 0;
	all->flagi.d = 0;
	all->flagi.a = 0;
	all->flagi.l = 0;
	all->flagi.k = 0;
	all->flagi.pt = 0;
	all->flagi.count = 0;
	all->pos.x = 0;
	all->pos.y = 0;
	all->pos.xx = 0;
	all->pos.yy = 0;
	job_map(all);
}

void			initialization(char *map_cub, int args)
{
	t_all all;

	all.mlx.ptr = NULL;
	all.win.ptr = NULL;
	all.img.ptr = NULL;
	all.img.adr = NULL;
	all.rcst.zbuffer = NULL;
	all.pars.line = NULL;
	all.win.x = -1;
	all.win.y = -1;
	all.map.mapa = NULL;
	all.flagi.arg = args;
	all.ray.rad = M_PI * 1.5;
	all.pos.count_s = 0;
	all.rcst.c = 0;
	all.sp.c = 0;
	all.pars.fd = open(map_cub, O_RDONLY);
	if (all.pars.fd == -1)
        start_ex();
	initialization2(&all);
}

int				main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 2 || argc == 3)
	{
		while (argv[1][i])
			i++;
		if (ft_strncmp(".cub", &argv[1][i - 4], 4) != 0)
			start_ex();
	}
	if (argc == 3)
	{
		i = 0;
		while (argv[2][i])
			i++;
		if (ft_strncmp("--save", &argv[2][i - 6], 7) != 0)
			start_ex();
	}
	if (argc == 2 || argc == 3)
		initialization(argv[1], argc);
	else
		start_ex();
	return (0);
}
