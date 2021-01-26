/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:50:09 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/06 11:50:54 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *vrem_elem;

	if (!*del)
		return ;
	while (*lst)
	{
		vrem_elem = *lst;
		del((*lst)->content);
		*lst = vrem_elem->next;
		free(vrem_elem);
	}
	*lst = NULL;
}
