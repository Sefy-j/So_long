/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:24:31 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/02/17 19:51:33 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_tiles {
	t_data	empty;
	t_data	wall;
	t_data	coll;
	t_data	exit;
	t_data	ply;
	t_data	ply2;
	t_data	enm;
	t_data	enm2;
}	t_tiles;

typedef struct s_map {
	char	**map;
	int		mapsize[2];
	int		plypos[2];
	int		tiles[3];
	int		exit;
	int		win;
	int		movements;
	int		time;
	int		enemies;
	t_vars	vars;
	t_tiles	imtls;
}	t_map;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	ERRGENERAL = 1,
	ERREMPTMAP = 2,
	ERRMAPCHAR = 3,
	ERRMAPSIZE = 4,
	ERRARG = 5,
	ERRMAPBIG = 6,
	ERRWALL = 7,
	ERRTILES = 8
};

enum {
	SZEIMG = 32,
	MAXWIDTH = 5120,
	MAXHEIGHT = 2880
};

enum {
	PLAYER = 0,
	COLLECTIBLE = 1,
	EXIT = 2
};

enum {
	X = 0,
	Y = 1
};

# define MAPCHAR "01CEP"
# define VERDE 0x0000FF00

void	ft_putstr_fd(char *s, int fd);
void	ft_errors(int error, char *name);
void	ft_freemap(char **map);
void	ft_checktiles(t_map *map);
void	ft_startwindow(t_map map);
void	ft_printmovecount(t_map *map);
void	ft_winlose(t_map *map, int win);
void	ft_moveup(t_map *map);
void	ft_movedown(t_map *map);
void	ft_moveleft(t_map *map);
void	ft_moveright(t_map *map);
void	ft_enemy(t_map *map, int enemies);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
int		ft_strncmp(const char *sr1, const char *sr2, size_t n);
int		ft_destroywindow(t_map *map);
int		ft_keypress(int keycode, t_map *map);
int		ft_printmap(t_map *map);
size_t	ft_strlen(const char *str);

#endif
