/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarras <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:33:56 by abarras           #+#    #+#             */
/*   Updated: 2022/11/24 11:33:59 by abarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_line_gnl(char *stash)
{
	char	*final;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	final = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		final[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		final[i++] = '\n';
	final[i] = '\0';
	return (final);
}

char	*ft_free_gnl(char *stash, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(stash, buffer);
	free(stash);
	return (temp);
}

char	*ft_bonus_gnl(char *stash)
{
	int		i;
	int		j;
	char	*back;

	i = ft_strchr_bis(stash, '\n');
	if (i == -1)
	{
		free (stash);
		return (NULL);
	}
	back = ft_calloc(sizeof(char), ft_strlen(stash) - i + 1);
	i++;
	j = 0;
	while (stash[i])
	{
		back[j] = stash[i];
		i++;
		j++;
	}
	free (stash);
	return (back);
}

char	*ft_read_gnl(int fd, char *stash)
{
	char	*buffer;
	int		s;

	s = -1;
	if (!stash)
		stash = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	s = 1;
	while (s > 0)
	{
		s = read(fd, buffer, BUFFER_SIZE);
		if (s == -1)
		{
			free (stash);
			free (buffer);
			return (NULL);
		}
		buffer[s] = 0;
		stash = ft_free_gnl(stash, buffer);
		if (ft_strchr_bis(buffer, '\n') != -1)
			break ;
	}
	free (buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*final;

	if (read(fd, 0, 0) < 0)
	{
		free (stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	if (fd > 4096 || fd < 0 || BUFFER_SIZE <= 0)
	{
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_read_gnl(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	final = ft_line_gnl(stash[fd]);
	stash[fd] = ft_bonus_gnl(stash[fd]);
	return (final);
}
