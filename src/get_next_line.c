/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <slisandr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:50:19 by slisandr          #+#    #+#             */
/*   Updated: 2020/09/28 05:10:13 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns:
** - (-1) if couldn't find '\n' in a string
** - some integer - position of the first '\n' found in the string
*/

int		get_endline_symbol_position(char *tail)
{
	int		i;

	i = 0;
	while (tail[i] != '\n' && tail[i] != '\0')
		i++;
	if (tail[i] == '\n')
	{
		tail[i] = '\0';
		return (i);
	}
	else
		return (-1);
}

char	*increase_tail(char *tail, char *buff)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (tail)
		i = ft_strlen(tail);
	if (buff)
		j = ft_strlen(buff);
	if (!(ptr = (char *)ft_memalloc(sizeof(*ptr) * (i + j + 1))))
		return (NULL);
	ft_memcpy(ptr, tail, i);
	ft_memcpy(ptr + i, buff, j);
	ptr[i + j] = '\0';
	ft_strdel(&tail);
	ft_bzero(buff, BUFF_SIZE + 1);
	return (ptr);
}

/*
** This function chops line ('\n'-ending piece) from the tail
** It returns:
** - (0) if there is nothing left to cut
** - (1) if cut successfully
*/

int		cut_off_line(char **tail, char **buff, char **line)
{
	int		endl_position;
	char	*leftover;

	*tail = increase_tail(*tail, *buff);
	endl_position = get_endline_symbol_position(*tail);
	if (endl_position > -1)
	{
		*line = ft_strdup(*tail);
		leftover = *tail;
		*tail = ft_strdup(*tail + endl_position + 1);
		ft_strdel(&leftover);
		return (1);
	}
	return (0);
}

/*
** This function is called iteratively upon tail when
** there is nothing more to be appended to it
*/

int		cut_from_remainder(char **tail, char **line, char **buff)
{
	if (cut_off_line(tail, buff, line))
	{
		ft_strdel(buff);
		return (1);
	}
	ft_strdel(buff);
	if (ft_strlen(*tail) > 0)
	{
		*line = ft_strdup(*tail);
		ft_strdel(tail);
		return (1);
	}
	return (0);
}

/*
** get_next_line() returns:
** - (-1) on error
** - (1) if successfully read new line
** - (0) if no more lines present
*/

int		get_next_line(int const fd, char **line)
{
	static char		*tail[12000];
	char			*buff;
	int				got_new_line;
	int				ret;

	buff = ft_strnew(BUFF_SIZE);
	if (BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, buff, 0)) < 0)
	{
		ft_strdel(&buff);
		return (-1);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		got_new_line = cut_off_line(&tail[fd], &buff, line);
		ft_strdel(&buff);
		if (got_new_line == 1)
			return (1);
		buff = ft_strnew(BUFF_SIZE);
	}
	if ((got_new_line = cut_from_remainder(&tail[fd], line, &buff)))
		return (1);
	ft_strdel(&tail[fd]);
	return (0);
}
