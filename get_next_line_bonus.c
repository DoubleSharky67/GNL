/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:17:25 by ffeaugas          #+#    #+#             */
/*   Updated: 2022/10/26 13:04:45 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

static void	ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	ft_buftrim(char *buf)
{
	int	i;

	i = 0;
	if (ft_strchr(buf, '\n'))
	{
		ft_strcpy(buf, ft_strchr(buf, '\n'));
		while (buf[i])
			i++;
		while (i < BUFFER_SIZE)
		{
			buf[i] = '\0';
			i++;
		}
	}	
	else
		ft_bzero(buf, BUFFER_SIZE + 1);
}

static char	*ft_strjoin_line(char const *line, char const *buf)
{
	char	*addline;
	int		i;
	int		linelen;
	int		buflen;

	linelen = ft_strlen_line(line, '\0');
	buflen = ft_strlen_line(buf, '\n');
	addline = malloc(sizeof(char) * (linelen + buflen + 1));
	if (addline == NULL)
		return (NULL);
	ft_strcpy(addline, line);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		addline[linelen + i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		addline[linelen + i] = '\n';
	addline[linelen + buflen] = '\0';
	return (addline);
}

static char	*ft_grow_line(char *line, char *buf)
{
	char	*addline;

	if (!buf[0] && !line)
		return (NULL);
	if (!line)
		addline = ft_substr(buf, 0, ft_strlen_line(buf, '\n'));
	else
		addline = ft_strjoin_line(line, buf);
	if (!addline)
		return (NULL);
	return (addline);
}

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	int			end_check;

	buf[fd][BUFFER_SIZE] = '\0';
	line = NULL;
	end_check = BUFFER_SIZE;
	while (!ft_strchr(line, '\n') && end_check > 0)
	{
		tmp = line;
		if (!buf[fd][0])
			end_check = read(fd, buf[fd], BUFFER_SIZE);
		if (end_check < 0 && tmp)
		{
			free(tmp);
			return (NULL);
		}
		line = ft_grow_line(tmp, buf[fd]);
		ft_buftrim(buf[fd]);
		free(tmp);
	}
	return (line);
}
