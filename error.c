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

int	ft_alloc(char *argv1, t_data *data, int i)
{
	int		fd2;
	int		h;
	char	*test;

	fd2 = open(argv1, O_RDONLY);
	h = 0;
	while (test != NULL)
	{
		test = get_next_line(fd2);
		h++;
	}
	data->map.map_tab = malloc((sizeof(int) * h * i) + 1);
	close(fd2);
	return (h);
}

void	ft_error_3(t_data *data, int i)
{
	int	j;
	int	h;

	h = 0;
	j = 0;
	while (data->map.map_tab[h + 1] != '5')
	{
		if (data->map.map_tab[h] == 'P')
			break ;
		j++;
		if (data->map.map_tab[h] == '4')
		{
			j = 0;
			i++;
		}
		h++;
	}
	data->loc.lx = j * 50;
	data->loc.ly = i * 50;
}

int	ft_error_2(t_data *data, int fd, char **argv, int i)
{
	char	*line;
	int		h;
	int		j;

	line = get_next_line(fd);
	while (line[i] == '1')
		i++;
	if (line[i] != '\n')
		return (0);
	h = ft_alloc(argv[1], data, i) - 1;
	line[i] = '4';
	data->map.i = i + 1;
	data->map.map_tab = ft_strjoin("0", line);
	data->map.y = h;
	if (ft_check(argv[1], data, h) == 0)
		return (0);
	while (h > 1)
	{
		line = get_next_line(fd);
		line[i] = '4';
		data->map.map_tab = ft_strjoin(data->map.map_tab, line);
		h--;
	}
	data->map.map_tab = ft_strjoin(data->map.map_tab, "5");
	return (1);
}

int	flood_fill(t_data *data)
{
	data->map.end_check = 0;
	fill(data->map.map_tab, data->loc.lx / 50 + 1, data->loc.ly / 50, data);
	return (data->map.end_check);
}

int	ft_error(int argc, char **argv, t_data *data)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	if (argc == 2)
	{
		if (ft_error_2(data, fd, argv, i) == 0)
			return (0);
		ft_error_3(data, i);
		close (fd);
		if (flood_fill(data) == 0)
			return (0);
		return (1);
	}
	close (fd);
	return (0);
}
