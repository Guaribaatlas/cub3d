NAME=cub3d
SRC= sources/cub3d.c sources/get_cub3d.c sources/get_cub3d_tools.c sources/main.c sources/parser_info.c \
     sources/parser_map.c sources/utils.c Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c\
     sources/cub_utils.c sources/cubinit.c sources/dplcmt.c sources/texture.c

CC=gcc
RM= /bin/rm -rf

HPATH= -I ./includes/
CFLAGS= -Wall -Wextra -Werror $(HPATH)

all: $(NAME)

$(NAME): $(SRC)
	gcc $(CFLAGS) -o $(NAME) -I minilibx -L minilibx -lmlx  -L libft -lft -framework OpenGL -framework AppKit $(SRC)
clean:
	@echo "Removing executable"
	@$ $(NAME)

fclean: clean
	@echo "Removing binary file"
	@$(RM) $(NAME)

re: fclean all≤
