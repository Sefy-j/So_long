/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startwindow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:26:17 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/17 19:05:56 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroywindow(t_map *map)
{
	ft_freemap(map->map);
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	if (map->win == 1)
		ft_putstr_fd("YOU WIN!\n", 1);
	else if (map->win == -1)
		ft_putstr_fd("YOU LOSE!\n", 1);
	exit (0);
}

static void	ft_loadtilesimg2(t_map *map, int w, int h)
{
	map->imtls.ply.img = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->imtls.ply.img = mlx_xpm_file_to_image(map->vars.mlx, \
	"./img/Player.xpm", &w, &h);
	map->imtls.ply2.img = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->imtls.ply2.img = mlx_xpm_file_to_image(map->vars.mlx, \
	"./img/Player2.xpm", &w, &h);
	map->imtls.enm.img = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->imtls.enm.img = mlx_xpm_file_to_image(map->vars.mlx, \
	"./img/Enemy.xpm", &w, &h);
	map->imtls.enm2.img = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->imtls.enm2.img = mlx_xpm_file_to_image(map->vars.mlx, \
	"./img/Enemy2.xpm", &w, &h);
}

static void	ft_loadtilesimg(t_map *map)
{
	int		w;
	int		h;

	map->imtls.empty.img = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->imtls.empty.img = mlx_xpm_file_to_image(map->vars.mlx, \
	"./img/EmptyTile.xpm", &w, &h);
	map->imtls.wall.img = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->imtls.wall.img = mlx_xpm_file_to_image(map->vars.mlx, \
	"./img/WallTile.xpm", &w, &h);
	map->imtls.coll.img = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->imtls.coll.img = mlx_xpm_file_to_image(map->vars.mlx, \
	"./img/Collectible.xpm", &w, &h);
	map->imtls.exit.img = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->imtls.exit.img = mlx_xpm_file_to_image(map->vars.mlx, \
	"./img/Exit.xpm", &w, &h);
	ft_loadtilesimg2(map, w, h);
}

static void	ft_printwalls(t_map *map)
{
	int	pos[2];

	pos[X] = 0;
	pos[Y] = 0;
	while (pos[Y] < map->mapsize[Y])
	{
		while (pos[X] < map->mapsize[X])
		{
			if ((pos[Y] == 0 || pos[Y] == map->mapsize[Y] - 1))
				mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
				map->imtls.wall.img, SZEIMG * pos[X], SZEIMG * pos[Y]);
			else if ((pos[X] == 0 || pos[X] == map->mapsize[X] - 1))
				mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
				map->imtls.wall.img, SZEIMG * pos[X], SZEIMG * pos[Y]);
			pos[X]++;
		}
		pos[X] = 0;
		pos[Y]++;
	}
}

void	ft_startwindow(t_map map)
{
	map.exit = 0;
	map.movements = 0;
	map.win = 0;
	map.time = 0;
	map.vars.mlx = mlx_init();
	ft_loadtilesimg(&map);
	map.vars.win = mlx_new_window(map.vars.mlx, map.mapsize[X] * SZEIMG, \
	map.mapsize[Y] * SZEIMG, "So_long");
	ft_printwalls(&map);
	mlx_hook(map.vars.win, ON_DESTROY, 0L, ft_destroywindow, &map);
	mlx_key_hook(map.vars.win, ft_keypress, &map);
	mlx_loop_hook(map.vars.mlx, ft_printmap, &map);
	mlx_loop(map.vars.mlx);
}
