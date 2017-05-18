/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_double_newline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:13:38 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/15 13:37:03 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int						double_newline(char *overflow)
{
	int		nulls;
	char	*tmp;

	tmp = overflow;
	nulls = 0;
	while (*tmp)
		tmp++;
	while (tmp[nulls] == '\0')
		nulls++;
	return (nulls);
}

int						main(void)
{
	int		res;

	res = double_newline("dubs\0");
	printf("%d\n", res);
}
