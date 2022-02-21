/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maputils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:36:54 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/17 19:12:25 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printmovecount(t_map *map)
{
	char	*movements;

	map->movements++;
	movements = ft_itoa(map->movements);
	mlx_put_image_to_window(map->vars.mlx, \
	map->vars.win, map->imtls.wall.img, 0, 0);
	mlx_string_put(map->vars.mlx, map->vars.win, 2, 21, VERDE, movements);
	free(movements);
}

static void	ft_checkwalls(t_map *map)
{
	int	pos[2];

	pos[X] = 0;
	pos[Y] = 0;
	while (pos[Y] < map->mapsize[Y])
	{
		while (pos[X] < map->mapsize[X])
		{
			if ((pos[Y] == 0 || pos[Y] == map->mapsize[Y] - 1) \
			&& map->map[pos[Y]][pos[X]] != '1')
			{
				ft_freemap(map->map);
				ft_errors(ERRWALL, NULL);
			}
			else if ((pos[X] == 0 || pos[X] == map->mapsize[X] - 1) \
			&& map->map[pos[Y]][pos[X]] != '1')
			{
				ft_freemap(map->map);
				ft_errors(ERRWALL, NULL);
			}
			pos[X]++;
		}
		pos[X] = 0;
		pos[Y]++;
	}
}

static void	ft_checktiles2(t_map *map, int i, int *j, int *empty)
{
	if (map->map[i][*j] == 'P')
		map->tiles[PLAYER]++;
	if (map->map[i][*j] == 'C')
		map->tiles[COLLECTIBLE]++;
	if (map->map[i][*j] == 'E')
		map->tiles[EXIT]++;
	if (map->map[i][*j] == '0')
		(*empty)++;
	if (*empty == (map->mapsize[X] * map->mapsize[Y]) / 5)
	{
		map->map[i][*j] = 'N';
		map->enemies++;
		*empty = 0;
	}
	(*j)++;
}

void	ft_checktiles(t_map *map)
{
	int	i;
	int	j;
	int	empty;

	i = 0;
	j = 0;
	empty = 0;
	ft_checkwalls(map);
	map->tiles[PLAYER] = 0;
	map->tiles[COLLECTIBLE] = 0;
	map->tiles[EXIT] = 0;
	while (i < map->mapsize[Y])
	{
		while (j < map->mapsize[X])
			ft_checktiles2(map, i, &j, &empty);
		j = 0;
		i++;
	}
	if (map->tiles[PLAYER] != 1 || \
	map->tiles[COLLECTIBLE] < 1 || map->tiles[EXIT] < 1)
	{
		ft_freemap(map->map);
		ft_errors(ERRTILES, NULL);
	}
}
