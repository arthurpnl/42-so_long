NAME		=	so_long

CC			=	cc
FLAGS		=	-g3 -Wall -Wextra -Werror

# === LIBFT ===
LIBFT_PATH	=	Libft
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

# === MLX ===
MLX_PATH	=	mlx
MLX_FILE	=	libmlx.a
MLX_LIB		=	$(MLX_PATH)/$(MLX_FILE)
MLX_FLAGS	=	-L$(MLX_PATH) -lmlx -lX11 -lXext

# === SOURCES ===
FILES = srcs/check_file \
		srcs/free \
		srcs/hooks \
		srcs/map_check \
		srcs/map_check2 \
		srcs/parse \
		srcs/display \
		srcs/game_end \
		srcs/init \
		srcs/map_parse \
		srcs/move \
		srcs/pathfinding \
		srcs/mlx_setup \
		srcs/main

SRCS		=	$(addsuffix .c, $(FILES))
OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	-Iincludes -I$(LIBFT_PATH) -I$(MLX_PATH)

# === RULES ===
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
