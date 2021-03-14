
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 12:02:19 by sdunckel          #+#    #+#              #
#    Updated: 2020/01/18 06:40:32 by sdunckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= miniRT

SRCS_LIST		= \
					main.c \
					color.c \
					figures.c \
					math.c \
					pixel.c \
					ray.c \
					setup.c \

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= files

MLX 			= minilibx

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror

LFLAGS			= -framework OpenGL -framework AppKit

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -s -C $(MLX)
				@$(CC) $(CFLAGS) $(LFLAGS) -I $(HEADER) $(OBJS) -o $(NAME)

.c:.o
				@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

clean:
				@$(RM) $(OBJS)
				@make clean -C $(MLX)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

