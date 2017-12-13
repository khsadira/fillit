/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:59:45 by schakor           #+#    #+#             */
/*   Updated: 2017/12/13 10:45:04 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_treat_file(char *content, t_uint16 **ret, int i, int j)
{
	int			n;
	int			nb_return;

	*ret = (t_uint16*)malloc(sizeof(**ret) * ((ft_strlen(content)) / 21));
	ft_bzero(*ret, 26);
	n = 15;
	nb_return = 5;
	while (content[i])
	{
		if (content[i] == '#')
			(*ret)[j] |= 1 << n;
		else if (content[i] == '\n')
		{
			n++;
			nb_return--;
		}
		if (nb_return == 0)
		{
			j++;
			nb_return = 5;
			n = 16;
		}
		n--;
		i++;
	}
	size_t a = 0;
	while (a <= ft_strlen(content) / 21)
	{
		printf("ret[%zu] = %u\n", a, (*ret)[a]);
		a++;
	}
	a = 0;
	while (a <= ft_strlen(content) / 21)
	{
		printf("1 a = %zu ret[%zu] = %u\n", a, a, (*ret)[a]);
		while (((*ret)[a] & 34952) == 0)
			(*ret)[a] <<= 1;
		printf("2 a = %zu\n", a);
		while (((*ret)[a] & 61440) == 0)
			(*ret)[a] <<= 4;
		printf("ret[%zu] = %u et a = %zu\n", a, (*ret)[a], a);
		a++;
	}
}
