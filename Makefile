# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:20:20 by mdebbi            #+#    #+#              #
#    Updated: 2019/04/11 13:03:01 by mdebbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_DIR = ./libft

$(NAME):
	@make -C $(LIBFT_DIR)
	gcc -c srcs/*.c libft/*.c -I ./libft -I ./srcs
	ar -rc $(NAME) *.o

all: $(NAME)

clean:
	rm -f *.o
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
