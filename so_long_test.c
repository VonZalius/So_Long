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

void	render_2(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map_tab[i++] != '5')
	{
		if (data->map.map_tab[i] == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->wall.ref, ft_line(data, i), ft_colone(data, i));
	}
	i = 0;
	while (data->map.map_tab[i++] != '5')
	{
		if (data->map.map_tab[i] == 'C' || data->map.map_tab[i] == 'c')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->coins.ref, ft_line(data, i), ft_colone(data, i));
	}
	i = 0;
	while (data->map.map_tab[i++] != '5')
	{
		if (data->map.map_tab[i] == 'E')
			mlx_put_image_to_window
				(data->mlx_ptr, data->win_ptr, data->end.ref, ft_line(data, i),
					ft_colone(data, i));
	}
}

int	render_next_frame(t_data *data)
{
	static int	i;

	i++;
	if (i < 50)
		data->image = ft_new_sprite(data->mlx_ptr, "xpm/fish_key.xpm");
	else if (i > 50)
		data->image = ft_new_sprite(data->mlx_ptr, "xpm/fish_key_2.xpm");
	if (i == 100)
		i = 0;
	data->wall = ft_new_wall(data->mlx_ptr, "xpm/wall.xpm");
	data->coins = ft_new_coins(data->mlx_ptr, "xpm/coins.xpm");
	data->end = ft_new_end(data->mlx_ptr, "xpm/end.xpm");
	data->badguy = ft_new_badguy(data->mlx_ptr, "xpm/badguy.xpm");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	render_2(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.ref,
		data->loc.lx, data->loc.ly);
	render_bonus(data);
	return (0);
}

/*void	ft_map_setup(t_data *data)
{
	int	i;

	i = 0;
	data->map.map_tab = malloc(sizeof(int) * 101);
	while(i < 101)
	{
		data->map.map_tab[i] = '0';
		i++;
	}
	data->map.map_tab[1] = '0';
	data->map.map_tab[5] = '1';
	data->map.map_tab[10] = '4';
	data->map.map_tab[12] = '1';
	data->map.map_tab[20] = '4';
	data->map.map_tab[21] = '1';
	data->map.map_tab[26] = 'C';
	data->map.map_tab[28] = '1';
	data->map.map_tab[30] = '4';
	data->map.map_tab[31] = '1';
	data->map.map_tab[38] = 'E';
	data->map.map_tab[40] = '4';
	data->map.map_tab[41] = 'C';
	data->map.map_tab[47] = '1';
	data->map.map_tab[101] = '5';
}*/

void	ft_close(t_data *data)
{
	exit (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.map.coins_count = 0;
	data.loc.player = 0;
	data.loc.end = 0;
	data.map.move = 0;
	if (ft_error(argc, argv, &data) == 0)
	{
		write (1, "ERROR\nMap non valide\n", 21);
		return (0);
	}
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window
		(data.mlx_ptr, data.map.i * 50 - 50, data.map.y * 50, "mlx_42");
	data.img = mlx_new_image(data.mlx_ptr, data.map.i * 50, data.map.y * 50);
	data.addr = mlx_get_data_addr
		(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_hook(data.win_ptr, 17, 0, (void *)ft_close, &data);
	mlx_key_hook(data.win_ptr, ft_move_fish, &data);
	mlx_loop_hook(data.mlx_ptr, render_next_frame, &data);
	mlx_loop(data.mlx_ptr);
}
