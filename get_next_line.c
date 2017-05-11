/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:13:47 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/10 19:45:59 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

/**/
void					parse_data(char **overflow, char ***line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*overflow)[i] != '\n')
	{
		(**line)[j] = (*overflow)[i];
		j++;
		i++;
	}
	(**line)[j] = 0;
}
/**/

int						get_next_line(const int fd, char **line)
{
	int				rd;
	char			buff[BUFF_SIZE + 1];
	static char		*overflow;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	overflow = ft_memalloc(BUFF_SIZE + 1);
	overflow[0] = 0;
	while ((rd = read(fd, buff, BUFF_SIZE)) && rd > 0)
	{
		buff[rd] = 0;
		overflow = ft_strjoin(overflow, buff);
		if (ft_strchr(buff, '\n'))
			break;
	}
	parse_data(&(overflow), &line); 
	return (1);
}
