/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:35:00 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/17 19:51:26 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_map *map)
{
	if (map->map[map->plypos[Y] - 1][map->plypos[X]] == 'C')
	{
		map->tiles[COLLECTIBLE]--;
		if (map->tiles[COLLECTIBLE] == 0)
			map->exit = 1;
	}
	if (map->map[map->plypos[Y] - 1][map->plypos[X]] == 'N')
		ft_winlose(map, -1);
	else if (map->map[map->plypos[Y] - 1][map->plypos[X]] == 'E')
	{	
		if (map->exit == 1)
			ft_winlose(map, 1);
		else if (map->exit == 0)
			map->exit = -1;
		ft_moveup(map);
	}
	else if (map->exit == -1)
	{
		map->map[map->plypos[Y]][map->plypos[X]] = 'E';
		map->map[map->plypos[Y] - 1][map->plypos[X]] = 'P';
		map->exit = 0;
		ft_printmovecount(map);
	}
	else
		ft_moveup(map);
}

void	ft_down(t_map *map)
{
	if (map->map[map->plypos[Y] + 1][map->plypos[X]] == 'C')
	{
		map->tiles[COLLECTIBLE]--;
		if (map->tiles[COLLECTIBLE] == 0)
			map->exit = 1;
	}
	if (map->map[map->plypos[Y] + 1][map->plypos[X]] == 'N')
		ft_winlose(map, -1);
	else if (map->map[map->plypos[Y] + 1][map->plypos[X]] == 'E')
	{	
		if (map->exit == 1)
			ft_winlose(map, 1);
		else if (map->exit == 0)
			map->exit = -1;
		ft_movedown(map);
	}
	else if (map->exit == -1)
	{
		map->map[map->plypos[Y]][map->plypos[X]] = 'E';
		map->map[map->plypos[Y] + 1][map->plypos[X]] = 'P';
		map->exit = 0;
		ft_printmovecount(map);
	}
	else
		ft_movedown(map);
}

void	ft_left(t_map *map)
{
	if (map->map[map->plypos[Y]][map->plypos[X] - 1] == 'C')
	{
		map->tiles[COLLECTIBLE]--;
		if (map->tiles[COLLECTIBLE] == 0)
			map->exit = 1;
	}
	if (map->map[map->plypos[Y]][map->plypos[X] - 1] == 'N')
		ft_winlose(map, -1);
	else if (map->map[map->plypos[Y]][map->plypos[X] - 1] == 'E')
	{	
		if (map->exit == 1)
			ft_winlose(map, 1);
		else if (map->exit == 0)
			map->exit = -1;
		ft_moveleft(map);
	}
	else if (map->exit == -1)
	{
		map->map[map->plypos[Y]][map->plypos[X]] = 'E';
		map->map[map->plypos[Y]][map->plypos[X] - 1] = 'P';
		ft_printmovecount(map);
		map->exit = 0;
	}
	else
		ft_moveleft(map);
}

void	ft_right(t_map *map)
{
	if (map->map[map->plypos[Y]][map->plypos[X] + 1] == 'C')
	{
		map->tiles[COLLECTIBLE]--;
		if (map->tiles[COLLECTIBLE] == 0)
			map->exit = 1;
	}
	if (map->map[map->plypos[Y]][map->plypos[X] + 1] == 'N')
		ft_winlose(map, -1);
	else if (map->map[map->plypos[Y]][map->plypos[X] + 1] == 'E')
	{	
		if (map->exit == 1)
			ft_winlose(map, 1);
		else if (map->exit == 0)
			map->exit = -1;
		ft_moveright(map);
	}
	else if (map->exit == -1)
	{
		map->map[map->plypos[Y]][map->plypos[X]] = 'E';
		map->map[map->plypos[Y]][map->plypos[X] + 1] = 'P';
		map->exit = 0;
		ft_printmovecount(map);
	}
	else
		ft_moveright(map);
}

int	ft_keypress(int keycode, t_map *map)
{
	if (keycode == 13 && map->map[map->plypos[Y] - 1][map->plypos[X]] != '1')
	{
		ft_up(map);
		ft_enemy(map, map->enemies);
	}
	if (keycode == 1 && map->map[map->plypos[Y] + 1][map->plypos[X]] != '1')
	{
		ft_down(map);
		ft_enemy(map, map->enemies);
	}
	if (keycode == 0 && map->map[map->plypos[Y]][map->plypos[X] - 1] != '1')
	{
		ft_left(map);
		ft_enemy(map, map->enemies);
	}
	if (keycode == 2 && map->map[map->plypos[Y]][map->plypos[X] + 1] != '1')
	{
		ft_right(map);
		ft_enemy(map, map->enemies);
	}
	if (keycode == 53)
		ft_destroywindow(map);
	ft_printmap(map);
	return (0);
}
