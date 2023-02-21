# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nghoang <nghoang@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 16:20:55 by nghoang           #+#    #+#              #
#    Updated: 2023/02/20 16:32:40 by nghoang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
INCLUDE 	= include
LIBFT 		= libft
SRC_DIR 	= src/
OBJ_DIR 	= obj/
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra -I


SRC_FILES	= ft_printf ft_printf_hex ft_printf_ptr ft_printf_unsigned \
				ft_printf_utils

SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


all:		$(NAME)

$(NAME):	$(OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a $(NAME)
				@ar -rcs $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


clean:
				@rm -rf $(OBJ_DIR)
				@make clean -C $(LIBFT)

fclean:		clean
				@rm -rf $(NAME)
				@make fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re
