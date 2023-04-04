/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarras <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:34:07 by abarras           #+#    #+#             */
/*   Updated: 2023/03/24 11:34:09 by abarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_3(t_data *data, int j, int i, char *line)
{
	while (j < i - 1 && (line[j] == '0' || line[j] == '1'
			|| line[j] == 'C' || line[j] == 'P'
			|| line[j] == 'E' || line[j] == 'B'))
	{
		if (line[j] == 'C')
			data->map.coins_count++;
		else if (line[j] == 'P' && data->loc.player == 0)
			data->loc.player++;
		else if (line[j] == 'P' && data->loc.player != 0)
			return (0);
		else if (line[j] == 'E' && data->loc.end == 0)
			data->loc.end++;
		else if (line[j] == 'E' && data->loc.end != 0)
			return (0);
		j++;
	}
	return (j);
}

int	ft_check_2(t_data *data, int fd, int h, int i)
{
	int		j;
	char	*line;

	while (h > 2)
	{
		j = 1;
		line = get_next_line(fd);
		if (line[0] != '1' || line[i - 1] != '1' || line [i] != '\n')
			return (0);
		j = ft_check_3(data, j, i, line);
		if (j == 0)
			return (0);
		if (line[j + 1] != '\n')
			return (0);
		h--;
	}
	return (1);
}

int	ft_check(char *argv1, t_data *data, int h)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	i = 0;
	fd = open(argv1, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line[i] == '1')
		i++;
	if (line[i] != '\n')
		return (0);
	if (ft_check_2(data, fd, h, i) == 0)
		return (0);
	j = 0;
	line = get_next_line(fd);
	while (line[j] == '1')
		j++;
	if (j != i || data->loc.player != 1 || data->loc.end != 1
		|| line[j] != '\0' || data->map.coins_count == 0)
		return (0);
	close (fd);
	return (1);
}
