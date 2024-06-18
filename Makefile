NAME = fdf

CFLAGS = -Wall -Werror -Wextra -g

MINILBX = ./minilibx-linux/

SRC = main.c \
	  ft_init.c \
	  ft_errors.c \
	  ft_utils.c \
	  ft_utils_two.c \
	  ft_point.c \
	  ft_drawline.c \
	  ft_printline.c \
	  ft_colors.c \
	  ft_new_col.c \
	  ft_origine.c \
	  ./get_next_line/get_next_line.c \
	  ./get_next_line/get_next_line_utils.c \

OBJ = ${SRC:.c=.o}

CC = cc

LIBFT = ./libft/libft.a

all : ${NAME}

${NAME} : ${OBJ} ${LIBFT}
	make -C ${MINILBX} all
	${CC} ${CFLAGS} ${OBJ} $(LIBFT) -L${MINILBX} -lmlx_Linux -lX11 -lXext -o $(NAME)

${LIBFT} :
	make -C ./libft/ all

clean :
	make -C ${MINILBX} clean
	make -C ./libft/ clean
	rm -f ${OBJ}

fclean : clean
	make -C ./libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all fclean
