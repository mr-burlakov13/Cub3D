/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:43:58 by lhayward          #+#    #+#             */
/*   Updated: 2021/01/21 17:43:59 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	rezult_r(int a, int b, t_all *all, int fd)
{
	if (a > 2560 && all->flagi.arg == 2)
		a = 2560;
	if (b > 1440 && all->flagi.arg == 2)
		b = 1440;
	else if (a <= 0 || b <= 0)
		ex_clz(fd);
	all->win.x = a;
	all->win.y = b;
}

void	ggvp(t_all *all, char *line, int fd)
{
	int j;

	j = -1;
	while (line[++j])
	{
		if (!(ft_strchr1(MAP_SYM2, line[j])))
			ex_clz(fd);
		if (ft_strchr1(SYM_PLAYER, line[j]) && all->pos.y == 0)
		{
			all->pos.y = all->flagi.count + 0.5;
			all->pos.x = j + 0.5;
		}
		if (line[j] == '2')
			all->pos.count_s++;
	}
	all->flagi.count++;
}

void	gg2(t_all *all, t_list *head, int fd, char *line)
{
	int		nb;
	int		i;
	t_list	*tmp2;

	i = -1;
	tmp2 = head;
	prov1(all, fd);
	ft_lstadd_back(&head, ft_lstnew(line));
	nb = ft_lstsize(head);
	all->map.mapa = ft_calloc(nb + 1, sizeof(char *));
	i = -1;
	while (head)
	{
		tmp2 = head;
		all->map.mapa[++i] = head->content;
		head = head->next;
		free(tmp2);
	}
	free(head);
	valid_perim(all, nb, fd);
	valid_krug(all, fd);
	valid_igrok(all, fd);
}

void	pars1(t_all *all)
{
	t_list *head;

	head = NULL;
	while (get_next_line(all->pars.fd, &all->pars.line))
	{
		if (all->pars.line[0] == '\0' && all->flagi.pt == 0)
		{
			free(all->pars.line);
			continue;
		}
		prs5(all);
		all->pars.i = 0;
		prs6(all);
		while (APL == ' ' && all->flagi.pt == 0)
			all->pars.i++;
		prs7(all);
		if (ft_strchr1(MAP_8_ST, APL) && all->flagi.pt == 0)
		{
			prs8(all);
			continue;
		}
		prs9(all);
		ft_lstadd_back(&head, ft_lstnew(all->pars.line));
	}
	gg2(all, head, all->pars.fd, all->pars.line);
}
