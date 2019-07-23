NAME			=	ft_select

# Sources
SRC				=	srcs/action.c srcs/ft_select.c srcs/init.c \
					srcs/misc.c srcs/move.c srcs/print.c \
					srcs/signaux.c srcs/termcapfonc.c srcs/term_misc.c

LIBFT_FOLDER	=	libft
LIB_FOLDERS		=	-L$(LIBFT_FOLDER)
LIBS			=	-lft -ltermcap
# Compilation
CXX				=	gcc
CFLAGS			=	-Wall -Wextra -Werror #-O3
INCLUDES		=	-Iincludes -I$(LIBFT_FOLDER)/includes

# Linking
OBJ				=	$(SRC:.c=.o)

# Colors
GREEN			=	\033[32m
RESET			=	\033[0m

all: libft $(NAME)

$(NAME): $(OBJ)
	@printf "$(GREEN)[cc]$(RESET): done\n"
	@printf "$(GREEN)[ld]$(RESET): $(NAME)\n"
	@$(CXX) -o $(NAME) $(OBJ) $(LIB_FOLDERS) $(LIBS) $(LDFLAGS) $(INCLUDES)

.c.o: $(SRC)
	@printf "$(GREEN)[cc]$(RESET): $< -> $@\n"
	@printf "\e[1A"
	@gcc -c $< -o $@ $(INCLUDES) $(CFLAGS)
	@printf "\e[0K"

libft:
	@printf "$(GREEN)[mk]$(RESET): libft all\n";
	@make -C libft
	@printf "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): libft all done\n";

libft-clean:
	@printf "$(GREEN)[mk]$(RESET): libft clean\n";
	@make -C $(LIBFT_FOLDER) clean >/dev/null
	@printf "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): libft clean done\n";

libft-fclean:
	@printf "$(GREEN)[mk]$(RESET): libft fclean\n";
	@make -C $(LIBFT_FOLDER) fclean >/dev/null
	@printf "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): libft fclean done\n";

libft-re:
	@printf "$(GREEN)[mk]$(RESET): libft re\n";
	@make -C $(LIBFT_FOLDER) re
	@printf "\e[1A\e[0K"
	@printf "$(GREEN)[mk]$(RESET): libft re done\n";

clean: libft-clean
	@printf "$(GREEN)[rm]$(RESET): cleaned object files\n"
	@rm -rf $(OBJ)

fclean: clean libft-fclean
	@printf "$(GREEN)[rm]$(RESET): cleaned binary file\n"
	@rm -rf $(NAME)

re: fclean libft all

.PHONY: all libft libft-clean libft-fclean libft-re clean fclean re
