# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: smiller <smiller@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/12 10:13:17 by smiller       #+#    #+#                  #
#    Updated: 2021/10/23 16:35:44 by smiller       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

LIBFT_DIR = libft

LIBFT = libft.a

HEADER = /includes/ft_printf.h

OBJ = src/ft_printf.o \
	  src/ft_printf_assign.o \
	  src/ft_printf_scpct.o \
	  src/ft_printf_diupx.o \
	  src/ft_printf_nbrlen.o \
	  src/ft_printf_write.o \

YELLOW  = \x1b[33;01m
GREEN   = \x1b[32;01m
RESET   = \x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) ./$(NAME)
	@ar -rcs $(NAME) $(OBJ)
	@echo "$(GREEN) 📠 libftprintf library created $(RESET)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) print
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN) 📠 ft_printf clean $(RESET)"

fclean: clean
	@rm -f $(NAME) $(LIBFT) print
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN) 📠 ft_printf fcleaned $(RESET)"

re: fclean all

.PHONY: all clean fclean re
