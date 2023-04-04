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

int	ft_colone(t_data *data, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j != i)
	{
		if (data->map.map_tab[j] == '4')
			k = k + 50;
		j++;
	}
	return (k);
}

int	ft_line(t_data *data, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (k != i)
	{
		j = j + 50;
		if (k == 0)
			j = 0;
		if (data->map.map_tab[k] == '4')
			j = 0;
		k++;
	}
	return (j);
}

int	ft_collision_simple(t_data *data)
{
	int	i;
	int	j;

	i = data->loc.lx / 50 + 1;
	j = data->loc.ly / 50 * data->map.i;
	i = i + j;
	if (data->map.map_tab[i] == '1')
		return (1);
	if (data->map.map_tab[i] == 'C' || data->map.map_tab[i] == 'c')
	{
		data->map.map_tab[i] = '0';
		data->map.coins_count--;
		write (1, "Coin-Coin\n", 10);
	}
	if (data->map.map_tab[i] == 'E' && data->map.coins_count == 0)
	{
		data->map.end++;
		write (1, "Fini :V\n", 8);
	}
	ft_dead(data, i);
	return (0);
}
/*
int	ft_collision(t_data	*data)
{
	int	i;
	int	j;

	i = 0;
	while(i != 50)
	{
		j = 0;
		while(j != 50)
		{
			if((data->loc.lx + i == 100 && data->loc.ly + j == 100) ||
				(data->loc.lx + i == 100 && data->loc.ly + j + 1 == 150) ||
				(data->loc.lx + i + 1 == 150 && data->loc.ly + j == 100) ||
				(data->loc.lx + i + 1 == 150 && data->loc.ly + j + 1 == 150))
				return(1);
			j++;
		}
		i++;
	}
	return (0);
}*/
