/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:11:14 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/17 20:20:09 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freepos(int **enempos, int enemies)
{
	int	i;

	i = 0;
	while (i < enemies)
	{
		free(enempos[i]);
		i++;
	}
	free(enempos);
}

int	**ft_eneminit(int **enempos, int enemies)
{
	int	i;

	i = 0;
	while (i < enemies)
	{
		enempos[i] = malloc(sizeof(int *) * 2);
		i++;
	}
	return (enempos);
}

int	**ft_enemposition(t_map *map, int enemies)
{
	int	pos[2];
	int	**enempos;
	int	i;

	i = 0;
	pos[X] = 0;
	pos[Y] = 0;
	enempos = malloc(sizeof(int **) * enemies);
	enempos = ft_eneminit(enempos, enemies);
	while (pos[Y] < map->mapsize[Y])
	{
		while (pos[X] < map->mapsize[X])
		{
			if (map->map[pos[Y]][pos[X]] == 'N')
			{
				enempos[i][X] = pos[X];
				enempos[i][Y] = pos[Y];
				i++;
			}
			pos[X]++;
		}
		pos[X] = 0;
		pos[Y]++;
	}
	return (enempos);
}

void	ft_enemymovement(t_map *map, int *enempos)
{
	if (map->map[enempos[Y] - 1][enempos[X]] == '0')
	{
		map->map[enempos[Y]][enempos[X]] = '0';
		map->map[enempos[Y] - 1][enempos[X]] = 'N';
	}
	else if (map->map[enempos[Y] + 1][enempos[X]] == '0')
	{
		map->map[enempos[Y]][enempos[X]] = '0';
		map->map[enempos[Y] + 1][enempos[X]] = 'N';
	}
	else if (map->map[enempos[Y]][enempos[X] - 1] == '0')
	{
		map->map[enempos[Y]][enempos[X]] = '0';
		map->map[enempos[Y]][enempos[X] - 1] = 'N';
	}
	else if (map->map[enempos[Y]][enempos[X] + 1] == '0')
	{
		map->map[enempos[Y]][enempos[X]] = '0';
		map->map[enempos[Y]][enempos[X] + 1] = 'N';
	}
}

void	ft_enemy(t_map *map, int enemies)
{
	int	i;
	int	**enempos;

	i = 0;
	enempos = ft_enemposition(map, enemies);
	while (i < enemies)
	{
		ft_enemymovement(map, enempos[i]);
		i++;
	}
	ft_freepos(enempos, enemies);
}
