# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 12:51:21 by lud-adam          #+#    #+#              #
#    Updated: 2026/03/29 14:43:31 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re debug force

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
CFLAGS_DEBUG = -Wall -Wextra -MMD -g3 -D DEBUG=1

NAME = alum1
P_SRC = src/
P_OBJ = .obj/
P_INC = inc/
P_LIBFT = libft/

SRC =  \
	main.c \
	get_next_line.c \
	fill_vector.c \
	check_input.c \
	print_board.c	\
	ai.c \
	game.c \
	vector.c

SRCS = $(addprefix $(P_SRC), $(SRC))
OBJS = $(patsubst $(P_SRC)%.c,$(P_OBJ)%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)
LIBFT = $(P_LIBFT)libft.a
LIBS = -L$(P_LIBFT) -lft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(P_OBJ)%.o: $(P_SRC)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(P_INC) -I$(P_LIBFT) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(P_LIBFT)

clean:
	rm -rf $(P_OBJ)
	$(MAKE) -C $(P_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(P_LIBFT) fclean

re: fclean all

debug:
	$(MAKE) CFLAGS="$(CFLAGS_DEBUG)" all

-include $(DEPS)
