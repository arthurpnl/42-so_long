NAME	= so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
AR = ar rcs 
RM = rm -rf

LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)/libft.a

FILES = srcs/check_file 
		srcs/free
		srcs/hooks
		srcs/map_check
		srcs/map_check2
		srcs/parse
		srcs/display
		srcs/game_end
		srcs/init
		srcs/map_parse
		srcs/move
		srcs/pathfinding
		srcs/mlx_setup
		srcs/main

SRCS = $(addsufix .c, $(FILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re