SRCS	= so_long.c ft_startwindow.c ft_printmap.c ft_maputils.c ft_movements.c ft_enemy.c \
			ft_movementsutils.c ft_solongutils.c ft_utils.c get_next_line.c get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

SRCSB	= so_long.c ft_startwindow.c ft_printmap.c ft_maputils.c ft_movements.c ft_enemy.c \
			ft_movementsutils.c ft_solongutils.c ft_utils.c get_next_line.c get_next_line_utils.c

OBJB	= ${SRCSB:.c=.o}

NAME	= so_long

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

MLX = mlx

MLXDIR = ./mlx/

MLXNAME = libmlx.a

MLXFLAGS = -framework OpenGL -framework AppKit

MLXPATH = ${MLXDIR}${MLXNAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${MLXPATH}
				${CC} ${CFLAGS} -L${MLXDIR} -l${MLX} ${MLXFLAGS} ${OBJS} -o ${NAME}

${MLXPATH}:
				@make -C ${MLXDIR} 
				
bonus:		all ${OBJB}
				@make OBJS="${OBJB}"

all:		${NAME}

clean:
				${RM} ${OBJS} ${OBJB}
				make clean -C ${MLXDIR}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY:		all bonus clean fclean re rebonus
