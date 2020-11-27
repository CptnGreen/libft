/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slisandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:31:57 by slisandr          #+#    #+#             */
/*   Updated: 2020/11/27 20:31:00 by slisandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 1

/*
** This flag toggles whether gnl returns just standard output codes
** or additional too
*/

# define GNL_ENHANCED 1

typedef struct	s_fd
{
	char		*txt;
	char		*cur;
	int			fd;
}				t_fd;

int				get_next_line(int const fd, char **line);

#endif
