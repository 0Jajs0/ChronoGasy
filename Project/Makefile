NAME = crono_gasy
MLX = ./minilibx-linux/libmlx.a

CC = cc
RM = rm -rf

CFLAGS += -Wall -Wextra -Werror

SRC = ft_mlx.c ft_win.c main.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(MLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -lXext -lX11

$(MLX) :
	make -C minilibx-linux all

clean :
	$(RM) $(OBJ) && make -C minilibx-linux clean

fclean : clean
	$(RM) $(NAME)

re : fclean all
