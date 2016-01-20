/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:28:52 by avella            #+#    #+#             */
/*   Updated: 2016/01/20 16:09:29 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_var	*assign(t_var *v, int length, char *chaine, char *piece)
{
	v = (t_var *)malloc(sizeof(t_var) * 2);
	v->length = length + 1;
	v->count = 0;
	v->chaine = chaine;
	v->piece = piece;
	return (v);
}

int		returned_try(int count)
{
	if (count == 4)
		return (1);
	return (0);
}

char	*dp(const char *s1)
{
	int			index;
	char		*dupli;

	index = 0;
	dupli = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dupli == NULL)
	{
		return (NULL);
	}
	while (s1[index] != '\0')
	{
		dupli[index] = s1[index];
		index++;
	}
	dupli[index] = '\0';
	return (dupli);
}
