/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:29:41 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/17 15:22:00 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printenemy(t_map *map, int *pos)
{
	if (map->time >= 10 && map->time < 20)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
		map->imtls.enm.img, SZEIMG * pos[X], SZEIMG * pos[Y]);
	else
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
		map->imtls.enm2.img, SZEIMG * pos[X], SZEIMG * pos[Y]);
	map->time++;
	if (map->time == 20)
		map->time = 0;
}

void	ft_printplayer(t_map *map, int *pos)
{
	map->plypos[X] = pos[X];
	map->plypos[Y] = pos[Y];
	if (map->time >= 10 && map->time < 20)
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
		map->imtls.ply.img, SZEIMG * pos[X], SZEIMG * pos[Y]);
	else
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
		map->imtls.ply2.img, SZEIMG * pos[X], SZEIMG * pos[Y]);
	map->time++;
	if (map->time == 20)
		map->time = 0;
}

void	ft_printmap2(t_map *map, int *pos)
{
	while (map->map[pos[Y]][pos[X] + 1] != '\n')
	{
		if (map->map[pos[Y]][pos[X]] == '0')
			mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
			map->imtls.empty.img, SZEIMG * pos[X], SZEIMG * pos[Y]);
		else if (map->map[pos[Y]][pos[X]] == '1')
			mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
			map->imtls.wall.img, SZEIMG * pos[X], SZEIMG * pos[Y]);
		else if (map->map[pos[Y]][pos[X]] == 'C')
			mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
			map->imtls.coll.img, SZEIMG * pos[X], SZEIMG * pos[Y]);
		else if (map->map[pos[Y]][pos[X]] == 'E')
			mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
			map->imtls.exit.img, SZEIMG * pos[X], SZEIMG * pos[Y]);
		else if (map->map[pos[Y]][pos[X]] == 'P')
			ft_printplayer(map, pos);
		else if (map->map[pos[Y]][pos[X]] == 'N')
			ft_printenemy(map, pos);
		pos[X]++;
	}
}

int	ft_printmap(t_map *map)
{
	int		pos[2];

	pos[X] = 1;
	pos[Y] = 1;
	while (map->map[pos[Y] + 1])
	{
		ft_printmap2(map, pos);
		pos[X] = 1;
		pos[Y]++;
	}
	return (0);
}
