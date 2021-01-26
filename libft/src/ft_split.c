/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhayward <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:25:21 by lhayward          #+#    #+#             */
/*   Updated: 2020/11/04 22:32:04 by lhayward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void free2(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

static int	kolvo(char const *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			j++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (j);
}

static char	*slovo(char const *str, char c)
{
	char	*pop;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	pop = (char*)malloc(sizeof(char) * (i + 1));
	if (NULL == pop)
    {
		return (NULL);
    }
	i = 0;
	while (str[i] && str[i] != c)
	{
		pop[i] = str[i];
		i++;
	}
	pop[i] = '\0';
	return (pop);
}

char		**ft_split(char const *s, char c)
{
	char	**mas;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	mas = (char**)malloc(sizeof(char*) * (kolvo(s, c) + 1));
	if (NULL == mas)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			if (!(mas[j++] = slovo(&s[i], c)))
				free2(mas, j);
			while (s[i] && s[i] != c)
				i++;
		}
	}
	mas[j] = NULL;
	return (mas);
}
