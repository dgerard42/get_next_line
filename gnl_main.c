/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:17:53 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/10 20:11:13 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int			main(void)
{
	int		fd;
	char	*ptr;

	fd = open("test_files/test01", O_RDONLY);
	while (get_next_line(fd, &ptr) == 1)
	{
		printf("next line = %s\n", ptr);
		printf("*******************\n");
	}
}
