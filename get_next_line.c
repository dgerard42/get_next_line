/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:13:47 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/23 11:23:29 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void					increment_overflow(char **overflow)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (*overflow);
	while (*tmp != '\n' && *tmp != '\0')
		tmp++;
	if (*tmp == '\n')
		tmp++;
	while (*tmp != '\0')
		(*overflow)[i++] = *tmp++;
	while ((*overflow)[i] != '\0')
		(*overflow)[i++] = '\0';
}

void					parse_data(char **overflow, char **line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*overflow)[i] != '\n' && (*overflow)[i] != '\0')
		i++;
	(*line) = ft_memalloc(i + 1);
	i = 0;
	while ((*overflow)[i] != '\n' && (*overflow)[i] != '\0')
		(*line)[j++] = (*overflow)[i++];
	(*line)[j] = '\0';
}

int						get_next_line(const int fd, char **line)
{
	int				rd;
	char			buff[BUFF_SIZE + 1];
	static char		*overflow[MAX_FD];

	if (fd < 0 || BUFF_SIZE < 1 || !line || fd > MAX_FD ||
			(read(fd, buff, 0) < 0))
		return (-1);
	if (!(overflow[fd]))
		overflow[fd] = ft_memalloc(BUFF_SIZE + 1);
	while ((rd = read(fd, buff, BUFF_SIZE)) && rd > 0)
	{
		buff[rd] = '\0';
		overflow[fd] = ft_strjoini(overflow[fd], buff, 1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (rd == 0 && *overflow[fd] == 0)
	{
		ft_memdel((void**)&(overflow[fd]));
		return (0);
	}
	parse_data(&(overflow[fd]), line);
	increment_overflow(&(overflow[fd]));
	return (1);
}
