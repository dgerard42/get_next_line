/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:13:47 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/14 18:15:11 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void					increment_overflow(char **overflow)
{
	int i;
	char *tmp;

	i = 0;
	tmp = (*overflow);
	while (*tmp != '\n')
		tmp++;
	if (*tmp == '\n')
		tmp++;
	while (*tmp != '\0')
		(*overflow)[i++] = *tmp++;
	while ((*overflow)[i] != '\0')
		(*overflow)[i++] = '\0';
}

void					parse_data(char **overflow, char ***line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*overflow)[i] != '\n' && (*overflow)[i] != '\0')
		i++;
	(**line) = ft_memalloc(i + 1);
	i = 0; 
	while ((*overflow)[i] != '\n' && (*overflow)[i] != '\0')
		(**line)[j++] = (*overflow)[i++];
	(**line)[j] = 0;
}

int						get_next_line(const int fd, char **line)
{
	int				rd;
	char			buff[BUFF_SIZE + 1];
	static char		*overflow;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!(overflow))
		overflow =  ft_memalloc(BUFF_SIZE + 1);
	while ((rd = read(fd, buff, BUFF_SIZE)) && rd > 0)
	{
		buff[rd] = 0;
		overflow = ft_strjoin(overflow, buff);
		if (ft_strchr(buff, '\n') || rd == 0)
			break;
	}
	if (rd == 0 && *overflow == 0)
		return (0);
	parse_data(&(overflow), &(line)); 
	increment_overflow(&(overflow));
	return (1);
}
