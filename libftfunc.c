/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 19:32:32 by avella            #+#    #+#             */
/*   Updated: 2016/01/20 16:06:06 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char const *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

int			ft_strlen2(const char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

int			all_try(char *chaine)
{
	if (good_end(chaine))
	{
		if (try_1(chaine))
		{
			if (try_2(chaine, 0, 0, 0))
			{
				if (try_3(chaine, 0, 0, 0))
				{
					if (try_4(chaine))
					{
						return (1);
					}
				}
			}
		}
	}
	return (0);
}
