/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:17:53 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/16 22:06:38 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int			main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("test_files/nonewline.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("next line = %s\n", line);
		printf("*******************\n");
	}
}
