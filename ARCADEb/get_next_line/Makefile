# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 21:49:06 by gbarone           #+#    #+#              #
#    Updated: 2023/07/27 02:36:30 by gbarone          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	get_next_line.c get_next_line_utils.c

OBJS			= $(SRCS:.c=.o)

BONUS			=	get_next_line_bonus.c get_next_line_utils_bonus.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= GNL.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
				
.SILENT:
