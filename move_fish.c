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

void	ft_move_fish_2(t_data *data)
{
	data->loc.ly = data->loc.ly - 50;
	if (ft_collision_simple(data) == 1)
		data->loc.ly = data->loc.ly + 50;
}

void	ft_move_fish_3(t_data *data)
{
	data->loc.lx = data->loc.lx - 50;
	if (ft_collision_simple(data) == 1)
		data->loc.lx = data->loc.lx + 50;
}

void	ft_move_fish_4(t_data *data)
{
	data->loc.ly = data->loc.ly + 50;
	if (ft_collision_simple(data) == 1)
		data->loc.ly = data->loc.ly - 50;
}

void	ft_move_fish_5(t_data *data)
{
	data->loc.lx = data->loc.lx + 50;
	if (ft_collision_simple(data) == 1)
		data->loc.lx = data->loc.lx - 50;
}

int	ft_move_fish(int key, t_data *data)
{
	if (key == 13)
		ft_move_fish_2(data);
	else if (key == 0)
		ft_move_fish_3(data);
	else if (key == 1)
		ft_move_fish_4(data);
	else if (key == 2)
		ft_move_fish_5(data);
	else if (key == 53)
		exit (0);
	data->map.move++;
	return (0);
}
