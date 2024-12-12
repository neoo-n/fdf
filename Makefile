CC = cc
CFLAGS = -Wall -Wextra -g -Iminilibx-linux
MLX_FLAGS = -Lmlx -lmlx_Linux -lXext -lX11 -lm

SRC = main.c my_mlx_pixel_put.c
#OBJDIR = obj
OBJ = ${SRC:.c=.o}

NAME = fdf
LIBFT = libft/libft.a
MLX = mlx/libmlx_Linux.a
RM = rm


all : ${NAME} 

${NAME} : ${OBJ} ${LIBFT} ${MLX}
		@${CC} ${CFLAGS} ${OBJ} ${LIBFT} -o ${NAME} ${MLX_FLAGS}

.o : .c
		@${CC} ${CFLAGS} -c $<

#${OBJDIR} :
#       mkdir -p ${OBJDIR}

${LIBFT} :
		@${MAKE} -C ./libft/

${MLX} :
		cd mlx && ./configure
		cd ..

clean :
		@${RM} -f ${OBJ}
		@${MAKE} -C ./libft clean

fclean :        clean
		@${RM} -f ${NAME}
		@${MAKE} -C ./libft fclean

re : fclean all

.PHONY : all clean fclean re