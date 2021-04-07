# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 12:02:19 by sdunckel          #+#    #+#              #
#    Updated: 2021/04/07 14:45:46 by liafigli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= miniRT

SRCS_LIST		= \
					main.c \
					events.c \
					ft_printf.c \
					

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs

LIB				= libft
MLX 			= minilibx

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror

LFLAGS			= -lmlx -framework OpenGL -framework AppKit

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -s -C $(LIB)
				@$(CC) $(CFLAGS) $(LFLAGS) -I $(LIB)/$(HEADER)/libft.h libft/libft.a $(OBJS) -o $(NAME)	

clean:
				@$(RM) $(OBJS)
				@make clean -C $(LIB)
				@$(RM) minirt.a

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(MLX)/mlx.h.gch
				@$(RM) $(HEADER)/elements.h.gch $(HEADER)/mini_rt.h.gch
				@make fclean -C $(LIB)

re:				fclean all
