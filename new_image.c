/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:42:52 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:42:55 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	sprite_mas(t_all *all)
{
	int i;
	int a;
	int j;

	if (!(all->spr = (t_spr *)malloc(sizeof(t_spr) * all->pos.count_s)))
		exit(0);
	i = -1;
	a = 0;
	while (AMM[++i])
	{
		j = -1;
		while (AMM[i][++j])
			if (AMM[i][j] == '2')
			{
				all->spr[a].y = i + 0.5;
				all->spr[a].x = j + 0.5;
				a++;
			}
	}
}

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->img.adr + (y * all->img.size_len + x * (all->img.bi_p_p / 8));
	*(unsigned int*)dst = color;
}

void	new_pict(t_all *all)
{
	all->img.ptr = mlx_new_image(all->mlx.ptr, all->win.x, all->win.y);
	all->img.adr = mlx_get_data_addr(all->img.ptr, &all->img.bi_p_p,
	&all->img.size_len, &all->img.endian);
	all->tex.nort.adress = mlx_xpm_file_to_image(all->mlx.ptr,
	all->tex.nort.name, &all->tex.nort.witdh, &all->tex.nort.visota);
	all->tex.nort.textur = mlx_get_data_addr(all->tex.nort.adress,
	&all->tex.nort.bpp, &all->tex.nort.len, &all->tex.nort.end);
	all->tex.east.adress = mlx_xpm_file_to_image(all->mlx.ptr,
	all->tex.east.name, &all->tex.east.witdh, &all->tex.east.visota);
	all->tex.east.textur = mlx_get_data_addr(all->tex.east.adress,
	&all->tex.east.bpp, &all->tex.east.len, &all->tex.east.end);
	all->tex.south.adress = mlx_xpm_file_to_image(all->mlx.ptr,
	all->tex.south.name, &all->tex.south.witdh, &all->tex.south.visota);
	all->tex.south.textur = mlx_get_data_addr(all->tex.south.adress,
	&all->tex.south.bpp, &all->tex.south.len, &all->tex.south.end);
	all->tex.west.adress = mlx_xpm_file_to_image(all->mlx.ptr,
	all->tex.west.name, &all->tex.west.witdh, &all->tex.west.visota);
	all->tex.west.textur = mlx_get_data_addr(all->tex.west.adress,
	&all->tex.west.bpp, &all->tex.west.len, &all->tex.west.end);
	all->tex.sprite.adress = mlx_xpm_file_to_image(all->mlx.ptr,
	all->tex.sprite.name, &all->tex.sprite.witdh, &all->tex.sprite.visota);
	all->tex.sprite.textur = mlx_get_data_addr(all->tex.sprite.adress,
	&all->tex.sprite.bpp, &all->tex.sprite.len, &all->tex.sprite.end);
}
