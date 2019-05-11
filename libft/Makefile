# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeiflin <akeiflin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 21:42:42 by akeiflin          #+#    #+#              #
#    Updated: 2019/03/27 14:39:25 by akeiflin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MAKELIB = ft_abs.c ft_atoi.c ft_bzero.c ft_isalnum.c \
		  ft_isalpha.c ft_isascii.c ft_isdigit.c \
		  ft_ispositive.c ft_isprint.c ft_itoa.c \
		  ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
		  ft_lstiter.c ft_lstmap.c ft_lstnew.c \
		  ft_memalloc.c ft_memccpy.c ft_memchr.c \
		  ft_memcmp.c ft_memcpy.c ft_memdel.c \
		  ft_memmove.c ft_memset.c ft_numlen.c \
		  ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
		  ft_putstr.c ft_putstr_fd.c ft_strcat.c \
		  ft_strchr.c ft_strclr.c ft_strcmp.c \
		  ft_strcpy.c ft_strdel.c ft_strdup.c \
		  ft_strequ.c ft_striter.c ft_striteri.c \
		  ft_strjoin.c ft_strlcat.c ft_strlen.c \
		  ft_strmap.c ft_strmapi.c ft_strncat.c \
		  ft_strncmp.c ft_strncpy.c ft_strnequ.c \
		  ft_strnew.c ft_strnstr.c ft_strrchr.c \
		  ft_strsplit.c ft_strstr.c ft_strsub.c \
		  ft_strtrim.c ft_tolower.c ft_toupper.c \
		  ft_lstaddnew.c ft_strfjoin.c ft_lstappendnew.c \
		  ft_lstsort.c ft_lstlen.c ft_putstrlen.c \
		  ft_putstrlenendl.c ft_strduplen.c ft_strljoin.c \
		  ft_strrev.c ft_calloc.c ft_memdup.c \
		  ft_hashtable.c ft_malloc.c ft_vjoin.c \
		  ft_vprint.c ft_free.c ft_replacestr.c \
		  ft_strlreplace.c get_next_line.c

OBJ = $(MAKELIB:.c=.o)

INCLUDES	=	./includes
FLAGS		=	-Wall -Wextra -Werror -O3 -Ofast -std=c99

# Colors
GREEN		=	\033[32m
RESET		=	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)[cc]$(RESET): done\n"
	@printf "$(GREEN)[ld]$(RESET): $(NAME)\n"
	@ar rcs $(NAME) $(OBJ)

.c.o: $(SRC)
	@printf "$(GREEN)[cc]$(RESET): $< -> $@\n"
	@printf "\e[1A"
	@gcc -c $< -o $@ -I $(INCLUDES) $(FLAGS)
	@printf "\e[0K"

clean:
	@printf "$(GREEN)[rm]$(RESET): object files\n"
	@rm -rf $(OBJ)

fclean: clean
	@printf "$(GREEN)[rm]$(RESET): library file\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
