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

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line_bonus.h"
# include "ft_printf.h"
# include "./mlx/mlx.h"

typedef struct s_nbr {
	void	*ref;
	char	*pxl;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_nbr;

typedef struct s_badguy {
	void	*ref;
	char	*pxl;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_badguy;

typedef struct s_end {
	void	*ref;
	char	*pxl;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_end;

typedef struct s_coins {
	void	*ref;
	char	*pxl;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_coins;

typedef struct s_wall {
	void	*ref;
	char	*pxl;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_wall;

typedef struct s_image {
	void	*ref;
	char	*pxl;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_image;

typedef struct s_loc_wall {
	int		wall_x;
	int		wall_y;
}				t_loc_wall;

typedef struct s_loc {
	int		lx;
	int		ly;
	int		player;
	int		end;
}				t_loc;

typedef struct s_map {
	char	*map_tab;
	int		coins_count;
	int		end;
	int		i;
	int		y;
	int		end_check;
	int		move;
}				t_map;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_image		image;
	t_loc		loc;
	t_wall		wall;
	t_map		map;
	t_coins		coins;
	t_end		end;
	t_badguy	badguy;
	t_nbr		nbr;
}				t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_end		ft_new_end(void *mlx_ptr, char *path);
t_coins		ft_new_coins(void *mlx_ptr, char *path);
t_wall		ft_new_wall(void *mlx_ptr, char *path);
t_image		ft_new_sprite(void *mlx_ptr, char *path);
int			ft_colone(t_data *data, int i);
int			ft_line(t_data *data, int i);
int			ft_collision_simple(t_data *data);
int			ft_move_fish(int key, t_data *data);
int			ft_check(char *argv1, t_data *data, int h);
int			ft_error(int argc, char **argv, t_data *data);
void		fill(char *map, int x, int y, t_data *data);
void		render_bonus(t_data *data);
t_badguy	ft_new_badguy(void *mlx_ptr, char *path);
void		ft_dead(t_data *data, int i);
t_nbr		ft_new_nbr(void *mlx_ptr, char *path);

#endif
