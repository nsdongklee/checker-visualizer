/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:25:40 by dongklee          #+#    #+#             */
/*   Updated: 2021/05/06 18:37:21 by dongklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*ft_strndup(char *s, int n)
{
	int		i;
	char	*ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

static int	read_line(char **line, char **str, char *newline)
{
	char	*temp;
	int		len;

	*newline = '\0';
	len = ft_strlen(*str);
	*line = ft_strndup(*str, len);
	if ((newline + 1) != NULL)
	{
		temp = ft_strdup(newline + 1);
		free(*str);
		*str = temp;
	}
	if ((newline + 1) == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (1);
}

static int	check_and_out(char **line, char **str)
{
	char	*newline;

	newline = NULL;
	if (*str && (newline = ft_strchr(*str, '\n')) != NULL)
		return (read_line(line, str, newline));
	else if (!newline && *str)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
	else if (!*str)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		buff[BUF_SIZE + 1];
	char		*swap;
	int			byte;

	if (fd < 0 || !line || BUF_SIZE <= 0)
		return (-1);
	while ((byte = read(fd, buff, BUF_SIZE)) > 0)
	{
		buff[byte] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			swap = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = swap;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (byte < 0)
		return (-1);
	return (check_and_out(line, &str[fd]));
}
