/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:13:47 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/10 11:37:58 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void					parse_data(char **overflow, char ***line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*overflow)[i] != '\n')
	{
		while ((*overflow)[i] == '\0')
			i++;
		(**line)[j] = (*overflow)[i];
		j++;
		i++;
	}
}

int						get_next_line(const int fd, char **line)
{
	int				rd;
	char			buff[BUFF_SIZE + 1];
	static char		**overflow;

	overflow = ft_2dstrnew(MAX_FD, BUFF_SIZE);
	while ((rd = read(fd, buff, 21)) && rd > 0)
	{
		buff[rd] = 0;
		overflow[fd] = ft_strjoin(overflow[fd], buff);
		if (ft_strchr(buff, '\n'))
			break;
	}
	parse_data(&(overflow[fd]), &line); 
	return (0);
}
