# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iallen <iallen@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/16 21:42:30 by iallen            #+#    #+#              #
#    Updated: 2017/07/16 21:54:27 by iallen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

FILES = eval.c ft_do_math.c ft_math.c ft_more_math.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -o $(NAME) $(FILES)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
