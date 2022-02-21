/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movementsutils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:58:48 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/17 15:22:00 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moveup(t_map *map)
{
	map->map[map->plypos[Y]][map->plypos[X]] = '0';
	map->map[map->plypos[Y] - 1][map->plypos[X]] = 'P';
	ft_printmovecount(map);
}

void	ft_movedown(t_map *map)
{
	map->map[map->plypos[Y]][map->plypos[X]] = '0';
	map->map[map->plypos[Y] + 1][map->plypos[X]] = 'P';
	ft_printmovecount(map);
}

void	ft_moveleft(t_map *map)
{
	map->map[map->plypos[Y]][map->plypos[X]] = '0';
	map->map[map->plypos[Y]][map->plypos[X] - 1] = 'P';
	ft_printmovecount(map);
}

void	ft_moveright(t_map *map)
{
	map->map[map->plypos[Y]][map->plypos[X]] = '0';
	map->map[map->plypos[Y]][map->plypos[X] + 1] = 'P';
	ft_printmovecount(map);
}
