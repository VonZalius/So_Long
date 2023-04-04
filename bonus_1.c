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

void	render_bonus(t_data *data)
{
	int		i;
	char	*path;

	i = 0;
	while (data->map.map_tab[i++] != '5')
	{
		if (data->map.map_tab[i] == 'B')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->badguy.ref, ft_line(data, i), ft_colone(data, i));
	}
	path = ft_strjoin("xpm/", ft_itoa(data->map.move % 10));
	path = ft_strjoin(path, ".xpm");
	data->nbr = ft_new_nbr(data->mlx_ptr, path);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->nbr.ref, 20, 0);
	path = ft_strjoin("xpm/", ft_itoa((data->map.move / 10) % 10));
	path = ft_strjoin(path, ".xpm");
	data->nbr = ft_new_nbr(data->mlx_ptr, path);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->nbr.ref, 10, 0);
	path = ft_strjoin("xpm/", ft_itoa(data->map.move / 100));
	path = ft_strjoin(path, ".xpm");
	data->nbr = ft_new_nbr(data->mlx_ptr, path);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->nbr.ref, 0, 0);
}

t_badguy	ft_new_badguy(void *mlx_ptr, char *path)
{
	t_badguy	badguy;

	badguy.ref = mlx_xpm_file_to_image(mlx_ptr, path, &badguy.x, &badguy.y);
	badguy.pxl = mlx_get_data_addr
		(badguy.ref, &badguy.bits_per_pixel,
			&badguy.line_length, &badguy.endian);
	return (badguy);
}

t_nbr	ft_new_nbr(void *mlx_ptr, char *path)
{
	t_nbr	nbr;

	nbr.ref = mlx_xpm_file_to_image(mlx_ptr, path, &nbr.x, &nbr.y);
	nbr.pxl = mlx_get_data_addr
		(nbr.ref, &nbr.bits_per_pixel,
			&nbr.line_length, &nbr.endian);
	return (nbr);
}

void	ft_dead(t_data *data, int i)
{
	if (data->map.map_tab[i] == 'B')
	{
		data->loc.lx = -50;
		data->loc.ly = -50;
		write (1, "T'es mort :D\n", 13);
		write (1, "Je t'ai ferme le jeu, ", 22);
		write (1, "il semblerait que c'est pas fait pour toi...\n", 45);
		exit (0);
	}
}
