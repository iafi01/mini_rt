
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
					pixel.c \
					point_op.c \
					vec_op.c \
					vec_point_base.c \
					setup.c \
					parse.c \
					parse_obj.c \
					get_next_line.c \
					get_next_line_utils.c \
					ray.c \
					bmp.c \

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= files

LIB				= libft
MLX 			= minilibx

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror

LFLAGS			= -lmlx -framework OpenGL -framework AppKit

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -s -C $(LIB)
				@$(CC) $(CFLAGS) $(LFLAGS) -I $(HEADER) $(LIB)/libft.a $(OBJS) -o $(NAME)
				

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

