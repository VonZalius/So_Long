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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 500 && y >= 0 && y < 500)
	{
		dst = data->addr + (y * data->line_length + \
		x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

t_end	ft_new_end(void *mlx_ptr, char *path)
{
	t_end	end;

	end.ref = mlx_xpm_file_to_image(mlx_ptr, path, &end.x, &end.y);
	end.pxl = mlx_get_data_addr
		(end.ref, &end.bits_per_pixel, &end.line_length, &end.endian);
	return (end);
}

t_coins	ft_new_coins(void *mlx_ptr, char *path)
{
	t_coins	coins;

	coins.ref = mlx_xpm_file_to_image(mlx_ptr, path, &coins.x, &coins.y);
	coins.pxl = mlx_get_data_addr
		(coins.ref, &coins.bits_per_pixel, &coins.line_length, &coins.endian);
	return (coins);
}

t_wall	ft_new_wall(void *mlx_ptr, char *path)
{
	t_wall	wall;

	wall.ref = mlx_xpm_file_to_image(mlx_ptr, path, &wall.x, &wall.y);
	wall.pxl = mlx_get_data_addr
		(wall.ref, &wall.bits_per_pixel, &wall.line_length, &wall.endian);
	return (wall);
}

t_image	ft_new_sprite(void *mlx_ptr, char *path)
{
	t_image	image;

	image.ref = mlx_xpm_file_to_image(mlx_ptr, path, &image.x, &image.y);
	image.pxl = mlx_get_data_addr
		(image.ref, &image.bits_per_pixel, &image.line_length, &image.endian);
	return (image);
}
