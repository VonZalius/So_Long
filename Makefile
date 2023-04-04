PATH_LIBFT =		libft/
PATH_MLX =			./mlx/
PATH_OBJS =			./objs/

MLX = $(PATH_MLX)libmlx.a
LIBFT = $(PATH_LIBFT)libft.a
NAME = so_long


#FILES =	$(PATH_GAME)test.c
FILES = $(wildcard *.c)
OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC = clang
CFLAGS = #-Wextra -Werror -Wall
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo objects done!!
	@$(MAKE) -C $(PATH_MLX)
	@$(MAKE) -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)
	@echo program done!

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)map
	@mkdir -p $(PATH_OBJS)gnl
	@mkdir -p $(PATH_OBJS)utils
	@mkdir -p $(PATH_OBJS)errors
	@mkdir -p $(PATH_OBJS)game
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(PATH_OBJS)
	@echo obj removed!

fclean: clean
	make clean -C $(PATH_MLX)
	make clean -C $(PATH_LIBFT)
	$(RM) $(NAME)
	@echo clean everything

re: fclean all

.PHONY: re all fclean clean
