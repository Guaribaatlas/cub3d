NAME=libft.a
SRC=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_putnbr_fd.c \
	ft_memmove.c ft_memset.c  ft_strchr.c ft_putendl_fd.c \
	ft_strcpy.c ft_strdup.c  ft_toupper.c ft_strlcpy.c ft_putstr_fd.c\
	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_split.c ft_putchar_fd.c\
	ft_strncmp.c ft_strnstr.c ft_calloc.c ft_itoa.c ft_strmapi.c \
	ft_strrchr.c ft_split.c ft_substr.c ft_strtrim.c ft_tolower.c

BONUS=ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c  \
	ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ= $(SRC:.c=.o)
OBJBONUS= $(BONUS:.c=.o)

CC=gcc
RM= /bin/rm -rf

HPATH= -I ./includes/
CFLAGS= -Wall -Wextra -Werror $(HPATH)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	@echo "Linking all files into .a file"
	@ar rc $@ $(OBJ)
	@ranlib $@
	@echo "Linked"

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "Removing all object files..."
	@$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
	@echo "Removing binary file"
	@$(RM) $(NAME)

re: fclean all

bonus: $(OBJ) $(OBJBONUS) libft.h
	@echo "Linking all files into .a file"
	@ar rc $(NAME) $(OBJ) $(OBJBONUS)
	@ranlib $(NAME)
	@echo "Linked"

rebonus: fcleanbonus bonus