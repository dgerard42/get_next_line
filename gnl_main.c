/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:17:53 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/18 21:03:07 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/**/
int			main(int ac,  char **av)
{
	int		fd;
	int		fd2;
	char	*line1 = 0;
	char	*line2 = 0;
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
		{
			printf("first file's line is: %s\n", line1);
			ft_memdel((void**)&line1);
		}
		if (y)
		{
			printf("second file's line is: %s\n", line2);
			ft_memdel((void**)&line2);
		}
	}
	ft_memdel((void**)&line1);
	ft_memdel((void**)&line2);
	close (fd);
	close (fd2);
}
/**/

/*
int				main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("test_files/test01", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("next line = %s\n", line);
		printf("********************\n");
	}
}
*/
