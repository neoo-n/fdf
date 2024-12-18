CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux
MLX_FLAGS = -Lmlx -lmlx_Linux -lXext -lX11 -lm

SRC = main.c my_mlx_pixel_put.c fdf.c error_exit.c\
		 create_map_2d.c fdf_utils.c pixel_drawn.c
#OBJDIR = obj
OBJ = ${SRC:.c=.o}

NAME = fdf
LIBFT = libft/libft.a
MLX = mlx/libmlx_Linux.a
RM = rm

PURPLE = \033[1;34m
CYAN = \033[2;36m
RESET = \033[0m


all : ${NAME} header

header:
	@echo "$(PURPLE)"
	@echo ".------..------..------."
	@echo "|F.--. ||D.--. ||F.--. |"
	@echo "| :(): || :/\: || :(): |"
	@echo "| ()() || (__) || ()() |"
	@echo "| '--'F|| '--'D|| '--'F|"
	@echo "\`------'\`------'\`------'"
	@echo "$(RESET)"

${NAME} : ${OBJ} ${LIBFT} ${MLX}
		@${CC} ${CFLAGS} ${OBJ} ${LIBFT} -o ${NAME} ${MLX_FLAGS}

.o : .c
		@${CC} ${CFLAGS} -c $<

#${OBJDIR} :
#       mkdir -p ${OBJDIR}

${LIBFT} :
		@echo "$(CYAN)"
		@${MAKE} -C ./libft/
		@echo "$(RESET)"

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