/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:17:53 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/17 17:28:45 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int			main(int ac,  char **av)
{
	int		fd;
	int		fd2;
	char	*line1;
	char	*line2;
	int		x;
	int		y;

	ac++;
	x = 1;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	while (x)
	{
		x = get_next_line(fd, &line1);
		y = get_next_line(fd2, &line2);
		if (x)
			printf("first file's line is: %s\n", line1);
		if (y)
			printf("second file's line is: %s\n", line2);
	}
	close (fd);
	close (fd2);
/*
	while (x)
	{
		x = get_next_line(fd, &line);
		printf("next line = %s\n", line);
		printf("%d\n", x);
		printf("*******************\n");
		if (x == 0)
			break;
	}*/
}
