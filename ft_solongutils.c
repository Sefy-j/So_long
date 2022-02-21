/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solongutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:47:28 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/17 15:05:43 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_winlose(t_map *map, int win)
{
	map->win = win;
	ft_destroywindow(map);
}

void	ft_errors(int error, char *name)
{
	if (error == ERRGENERAL)
		perror(name);
	if (error == ERREMPTMAP)
		ft_putstr_fd("Error\nEmpty map\n", 2);
	if (error == ERRMAPCHAR)
	{
		ft_putstr_fd("Error\n", 2);
		write(2, &name[0], 1);
		ft_putstr_fd(" is not a valid character\n", 2);
	}
	if (error == ERRMAPSIZE)
	{
		free(name);
		ft_putstr_fd("Error\nMap is not rectangular\n", 2);
	}
	if (error == ERRARG)
		ft_putstr_fd("Error\nPlease, insert a valid map\n", 2);
	if (error == ERRMAPBIG)
		ft_putstr_fd("Error\nMap bigger than computer screen\n", 2);
	if (error == ERRWALL)
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
	if (error == ERRTILES)
		ft_putstr_fd("Error\n\
Map has not starting position or enough collectibles or exits\n", 2);
	exit (ERRGENERAL);
}
