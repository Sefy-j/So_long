/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:32:14 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/17 20:26:37 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_checkmap2(char *line, size_t len, int fd, int *maplen)
{
	size_t	i;
	char	c;

	i = 0;
	while (line)
	{
		while (ft_strchr(MAPCHAR, line[i]))
			i++;
		if (line[i] != '\n')
		{
			c = line[i];
			free(line);
			ft_errors(ERRMAPCHAR, &c);
		}
		if (len != ft_strlen(line))
			ft_errors(ERRMAPSIZE, line);
		(*maplen)++;
		i = 0;
		len = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static int	ft_checkmap(char *mapfile)
{
	int		fd;
	char	*line;
	size_t	len;
	int		maplen;

	maplen = 0;
	fd = open(mapfile, O_RDONLY | O_CLOEXEC);
	if (fd == -1)
		ft_errors(ERRGENERAL, "open");
	line = get_next_line(fd);
	if (!line)
		ft_errors(ERREMPTMAP, NULL);
	len = ft_strlen(line);
	line = ft_checkmap2(line, len, fd, &maplen);
	free(line);
	if (close(fd) == -1)
		ft_errors(ERRGENERAL, "close");
	return (maplen);
}

static char	**ft_readmap(char *mapfile)
{
	int		fd;
	size_t	i;
	size_t	maplen;
	char	**map;

	i = 0;
	maplen = ft_checkmap(mapfile);
	map = (char **)malloc(sizeof(char *) * (maplen + 1));
	fd = open(mapfile, O_RDONLY | O_CLOEXEC);
	if (fd == -1)
		ft_errors(ERRGENERAL, "open");
	while (i < maplen)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	if (close(fd) == -1)
	{
		ft_freemap(map);
		ft_errors(ERRGENERAL, "close");
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	map;
	size_t	i;

	if (argc != 2)
		ft_errors(ERRARG, NULL);
	i = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + (i - 4), ".ber", 4))
		ft_errors(ERRARG, NULL);
	map.map = ft_readmap(argv[1]);
	map.mapsize[X] = ft_strlen(map.map[X]) - 1;
	map.mapsize[Y] = 0;
	while (map.map[map.mapsize[Y]])
		map.mapsize[Y]++;
	if (map.mapsize[X] * 32 > MAXWIDTH || map.mapsize[Y] * 32 > MAXHEIGHT)
	{
		ft_freemap(map.map);
		ft_errors(ERRMAPBIG, NULL);
	}
	map.enemies = 0;
	ft_checktiles(&map);
	ft_startwindow(map);
	return (0);
}
