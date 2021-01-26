/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:40:35 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 21:40:38 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_dynamic/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/include/libft.h"
# include "../get_next_line/get_next_line.h"
# include <math.h>

# define AMM all->map.mapa
# define SYM_PLAYER "ESNW"
# define MAP_SYM "02ESNW"
# define MAP_SYM2 "02ESNW 1"
# define MAP_8_ST "RNOSOWEEASFC"
# define S8 all->st_8
# define SPEED 0.1
# define W1 AMM[(int)(all->pos.y + all->dir.y * SPEED)][(int)all->pos.x]
# define W2 AMM[(int)(all->pos.y)][(int)(all->pos.x + all->dir.x * SPEED)]
# define S1 AMM[(int)(all->pos.y - all->dir.y * SPEED)][(int)all->pos.x]
# define S2 AMM[(int)(all->pos.y)][(int)(all->pos.x - all->dir.x * SPEED)]
# define D1 AMM[(int)all->pos.y][(int)(all->pos.x + all->plan.planex * SPEED)]
# define D2 AMM[(int)(all->pos.y + all->plan.planey * SPEED)][(int)all->pos.x]
# define A1 AMM[(int)all->pos.y][(int)(all->pos.x - all->plan.planex * SPEED)]
# define A2 AMM[(int)(all->pos.y - all->plan.planey * SPEED)][(int)all->pos.x]
# define APPX all->plan.planex * cos(-SPEED) - all->plan.planey * sin(-SPEED)
# define APPX2 all->plan.planex * cos(SPEED) - all->plan.planey * sin(SPEED)
# define AAPX3 all->dir.b * sin(-SPEED) + all->plan.planey * cos(-SPEED)
# define AAPX4 all->dir.b * sin(SPEED) + all->plan.planey * cos(SPEED)
# define APL all->pars.line[all->pars.i]
# define QQ (all->pos.x -  all->spr[k].x) * (all->pos.x -  all->spr[k].x)
# define BOD QQ + (all->pos.y - all->spr[k].y) * (all->pos.y - all->spr[k].y)
# define ATSV all->tex.sprite.visota
# define ASS all->sp.sht
# define NMN all->sp.y
# define WY all->win.y

# define BLACK 0x00000000

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SCALE 8

typedef struct			s_mlx
{
	void				*ptr;
	int					f;
}						t_mlx;

typedef struct			s_win
{
	void				*ptr;
	int					x;
	int					y;
}						t_win;

typedef struct			s_img
{
	void				*ptr;
	char				*adr;
	int					bi_p_p;
	int					size_len;
	int					endian;
}						t_img;

typedef struct			s_map
{
	char				**mapa;
	int					x;
	int					y;
	int					spr;
}						t_map;

typedef struct			s_st_8
{
	int					r;
	int					no;
	int					so;
	int					we;
	int					ea;
	int					s;
	int					f;
	int					c;
	int					count;
}						t_st_8;

typedef struct			s_flagi
{
	int					w;
	int					s;
	int					d;
	int					a;
	int					l;
	int					k;
	int					pt;
	int					arg;
	int					count;
}						t_flagi;

typedef struct			s_pos
{
	double				x;
	double				y;
	double				w;
	double				a;
	double				z;
	double				xx;
	double				yy;
	int					count_s;
}						t_pos;

typedef struct			s_plan
{
	double				planex;
	double				planey;
}						t_plan;

typedef struct			s_pol
{
	int					a;
	int					b;
	int					c;
}						t_pol;

typedef struct			s_potolok
{
	int					a;
	int					b;
	int					c;
}						t_potolok;

typedef struct			s_text1
{
	int					len;
	int					bpp;
	int					end;
	int					witdh;
	int					visota;
	char				*name;
	void				*adress;
	void				*textur;
}						t_text1;

typedef struct			s_tex
{
	t_text1				nort;
	t_text1				east;
	t_text1				south;
	t_text1				west;
	t_text1				sprite;
}						t_tex;

typedef struct			s_dir
{
	double				x;
	double				y;
	double				a;
	double				b;
}						t_dir;

typedef struct			s_ray
{
	double				x;
	double				y;
	double				rad;
}						t_ray;

typedef struct			s_rcst
{
	double				texpos;
	double				step;
	int					texx;
	int					texy;
	int					side;
	int					hit;
	int					stepx;
	int					stepy;
	int					y;
	int					x;
	int					drawstart;
	int					drawend;
	double				ddx;
	double				ddy;
	double				si_d_x;
	double				si_d_y;
	double				rdx;
	double				rdy;
	int					mapx;
	int					mapy;
	int					lh;
	double				pwd;
	double				*zbuffer;
	int					c;
	unsigned int		*co;
}						t_rcst;

typedef struct			s_spr
{
	double				x;
	double				y;
	double				d;
	int					first;
	int					second;
}						t_spr;

typedef struct			s_pars
{
	char				*line;
	int					fd;
	int					i;
}						t_pars;

typedef struct			s_sp
{
	double				spx;
	double				spy;
	double				trx;
	double				tryy;
	double				ivt;
	int					ssx;
	int					sht;
	int					swh;
	int					dsy;
	int					dey;
	int					dsx;
	int					dex;
	int					y;
	int					s;
	int					d;
	int					c;
	int					texx;
	int					texy;
	unsigned int		*color1;
}						t_sp;

typedef struct			s_all
{
	t_flagi				flagi;
	t_mlx				mlx;
	t_win				win;
	t_img				img;
	t_st_8				st_8;
	t_map				map;
	t_pos				pos;
	t_dir				dir;
	t_ray				ray;
	t_tex				tex;
	t_spr				*spr;
	t_plan				plan;
	t_potolok			potolok;
	t_pol				pol;
	t_rcst				rcst;
	t_pars				pars;
	t_sp				sp;
}						t_all;

void					pars1(t_all *all);
void					valid_igrok(t_all *all, int fd);
void					valid_krug(t_all *all, int fd);
void					valid_perim(t_all *all, int nb, int fd);
void					ex_clz(int fd);
void					new_pict(t_all *all);
int						key_press(int key, t_all *all);
int						escape(t_all *all);
void					picture(t_all *all);
int						job_map(t_all *all);
void					initialization(char *map_cub, int args);
void					initialization2(t_all *all);
void					st_8(t_all *all, char *line, int fd);
void					st_8_1(t_all *all, char *line, int fd);
void					st_8_2(t_all *all, char *line, int fd);
void					st_8_3(t_all *all, char *line, int fd);
void					st_8_4(t_all *all, char *line, int fd);
void					rezult_r(int a, int b, t_all *all, int fd);
void					start_ex();
int						key_press(int key, t_all *all);
int						key_un_press(int key, t_all *all);
int						key_press_finish(t_all *all);
void					my_mlx_pixel_put(t_all *all, int x, int y, int color);
void					pech_all(t_all *all);
void					pech_karta(t_all *all, int i, int j);
void					pech_igrok(t_all *all, int i, int j);
void					ft_cast_ray(t_all *all);
void					raycast(t_all *all);
int						get_nb(char *line, int fd);
int						get_nb2(char *str, int fd);
int						cvet(t_all *all);
int						cvet1(t_all *all);
void					route(char c, t_all *all);
void					route2(char c, t_all *all);
void					save(t_all *all);
int						konec(t_all *all, int win);
void					tex_color(t_all *all);
void					cikl_pech(t_all *all);
void					raydire(t_all *all);
void					hit(t_all *all);
void					vice(t_all *all);
void					sprite(t_all *all);
void					eror11(char *str, int fd);
void					sprite_mas(t_all *all);
void					free1(char **s);
void					ggvp(t_all *all, char *line, int fd);
void					prs5(t_all *all);
void					prs6(t_all *all);
void					prs7(t_all *all);
void					prs8(t_all *all);
void					prs9(t_all *all);
void					prov1(t_all *all, int fd);
void					dva1(t_all *all);
void					raz1(t_all *all);
void					tri1(t_all *all);
void					ch4(t_all *all);
void					spr1(t_all *all);
void					spr2(t_all *all);
void					spr3(t_all *all);
void					spr0(t_all *all);

#endif
