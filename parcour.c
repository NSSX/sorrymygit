/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcour.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:10:07 by avella            #+#    #+#             */
/*   Updated: 2016/01/20 15:45:40 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try(char *piece, char *chaine, int chainei, int length)
{
	int		pi;
	t_var	*v;

	v = NULL;
	v = assign(v, length, chaine, piece);
	pi = first_di(piece);
	if (v->piece[pi] == '#' && v->chaine[chainei] == '.')
		v->count++;
	else
		return (0);
	p_c_change(v, chainei, pi);
	if (pi + 1 < ft_strlen2(v->piece) && chainei + 1 < ft_strlen2(v->chaine))
		if (v->piece[pi + 1] == '#' && v->chaine[chainei + 1] == '.')
			v->count = go_right(chainei, pi, v);
	if (pi + 5 < ft_strlen2(v->piece) && chainei + 5 < ft_strlen2(v->chaine))
		if (v->piece[pi + 5] == '#' && v->chaine[chainei + v->length] == '.')
			v->count = go_down(chainei, pi, v);
	if (pi - 5 > 0 && chainei - 5 > 0)
		if (v->piece[pi - 5] == '#' && v->chaine[chainei - v->length] == '.')
			v->count = go_up(chainei, pi, v);
	if (pi - 5 > 0 && chainei - 5 > 0)
		if (v->piece[pi - 1] == '#' && v->chaine[chainei - 1] == '.')
			v->count = go_left(chainei, pi, v);
	free(v->piece);
	return (returned_try(v->count));
}

int		go_right(int ci, int pi, t_var *v)
{
	if (v->count < 4)
	{
		pi = pi + 1;
		ci = ci + 1;
		v->count++;
		v->piece[pi] = 'x';
		v->chaine[ci] = 'x';
		if (pi + 1 < ft_strlen2(v->piece) && ci + 1 < ft_strlen2(v->chaine))
			if (v->piece[pi + 1] == '#' && v->chaine[ci + 1] == '.')
				v->count = go_right(ci, pi, v);
		if (pi + 5 < ft_strlen2(v->piece) && ci + 5 < ft_strlen2(v->chaine))
			if (v->piece[pi + 5] == '#' && v->chaine[ci + v->length] == '.')
				v->count = go_down(ci, pi, v);
		if (pi - 5 > 0 && ci - 5 > 0)
			if (v->piece[pi - 5] == '#' && v->chaine[ci - v->length] == '.')
				v->count = go_up(ci, pi, v);
		if (pi - 1 > 0 && ci - 1 > 0)
			if (v->piece[pi - 1] == '#' && v->chaine[ci - 1] == '.')
				v->count = go_left(ci, pi, v);
	}
	return (v->count);
}

int		go_down(int ci, int pi, t_var *v)
{
	if (v->count < 4)
	{
		v->count++;
		pi = pi + 5;
		ci = ci + v->length;
		v->piece[pi] = 'x';
		v->chaine[ci] = 'x';
		if (pi + 1 < ft_strlen2(v->piece) && ci + 1 < ft_strlen2(v->chaine))
			if (v->piece[pi + 1] == '#' && v->chaine[ci + 1] == '.')
				v->count = go_right(ci, pi, v);
		if (pi + 5 < ft_strlen2(v->piece) && ci + 5 < ft_strlen2(v->chaine))
			if (v->piece[pi + 5] == '#' && v->chaine[ci + v->length] == '.')
				v->count = go_down(ci, pi, v);
		if (pi - 5 > 0 && ci - 5 > 0)
			if (v->piece[pi - 5] == '#' && v->chaine[ci - v->length] == '.')
				v->count = go_up(ci, pi, v);
		if (pi - 1 > 0 && ci - 1 > 0)
			if (v->piece[pi - 1] == '#' && v->chaine[ci - 1] == '.')
				v->count = go_left(ci, pi, v);
	}
	return (v->count);
}

int		go_up(int ci, int pi, t_var *v)
{
	if (v->count < 4)
	{
		v->count++;
		pi = pi - 5;
		ci = ci - v->length;
		v->piece[pi] = 'x';
		v->chaine[ci] = 'x';
		if (pi + 1 < ft_strlen2(v->piece) && ci + 1 < ft_strlen2(v->chaine))
			if (v->piece[pi + 1] == '#' && v->chaine[ci + 1] == '.')
				v->count = go_right(ci, pi, v);
		if (pi + 5 < ft_strlen2(v->piece) && ci + 5 < ft_strlen2(v->chaine))
			if (v->piece[pi + 5] == '#' && v->chaine[ci + v->length] == '.')
				v->count = go_down(ci, pi, v);
		if (pi - 5 > 0 && ci - 5 > 0)
			if (v->piece[pi - 5] == '#' && v->chaine[ci - v->length] == '.')
				v->count = go_up(ci, pi, v);
		if (pi - 1 > 0 && ci - 1 > 0)
			if (v->piece[pi - 1] == '#' && v->chaine[ci - 1] == '.')
				v->count = go_left(ci, pi, v);
	}
	return (v->count);
}

int		go_left(int ci, int pi, t_var *v)
{
	if (v->count < 4)
	{
		v->count++;
		pi = pi - 1;
		ci = ci - 1;
		v->piece[pi] = 'x';
		v->chaine[ci] = 'x';
		if (pi + 1 < ft_strlen2(v->piece) && ci + 1 < ft_strlen2(v->chaine))
			if (v->piece[pi + 1] == '#' && v->chaine[ci + 1] == '.')
				v->count = go_right(ci, pi, v);
		if (pi + 5 < ft_strlen2(v->piece) && ci + 5 < ft_strlen2(v->chaine))
			if (v->piece[pi + 5] == '#' && v->chaine[ci + v->length] == '.')
				v->count = go_down(ci, pi, v);
		if (pi - 5 > 0 && ci - 5 > 0)
			if (v->piece[pi - 5] == '#' && v->chaine[ci - v->length] == '.')
				v->count = go_up(ci, pi, v);
		if (pi - 1 > 0 && ci - 1 > 0)
			if (v->piece[pi - 1] == '#' && v->chaine[ci - 1] == '.')
				v->count = go_left(ci, pi, v);
	}
	return (v->count);
}
