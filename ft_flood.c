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

void	fill_2(char *map, int x, int y, t_data *data)
{
	if (map[y * data->map.i + x] == 'C')
	{
		map[y * data->map.i + x] = 'c';
		fill(data->map.map_tab, x + 1, y, data);
		fill(data->map.map_tab, x - 1, y, data);
		fill(data->map.map_tab, x, y + 1, data);
		fill(data->map.map_tab, x, y - 1, data);
	}
	if (map[y * data->map.i + x] == '0')
	{
		map[y * data->map.i + x] = 'o';
		fill(data->map.map_tab, x + 1, y, data);
		fill(data->map.map_tab, x - 1, y, data);
		fill(data->map.map_tab, x, y + 1, data);
		fill(data->map.map_tab, x, y - 1, data);
	}
}

void	fill(char *map, int x, int y, t_data *data)
{
	if (map[y * data->map.i + x] == 'E')
	{
		data->map.end_check = 1;
		return ;
	}
	if (map[y * data->map.i + x] == '1')
		return ;
	if (map[y * data->map.i + x] == 'P')
	{
		map[y * data->map.i + x] = 'p';
		fill(data->map.map_tab, x + 1, y, data);
		fill(data->map.map_tab, x - 1, y, data);
		fill(data->map.map_tab, x, y + 1, data);
		fill(data->map.map_tab, x, y - 1, data);
	}
	fill_2(map, x, y, data);
}
