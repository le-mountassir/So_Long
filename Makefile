# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 10:17:43 by ahel-mou          #+#    #+#              #
#    Updated: 2021/12/20 15:06:46 by ahel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

LB_SRC = ./my_lib/libft/ft_bzero.c ./my_lib/libft/ft_memcpy.c ./my_lib/libft/ft_memchr.c ./my_lib/libft/ft_memmove.c ./my_lib/libft/ft_memset.c ./my_lib/libft/ft_memcmp.c\
	./my_lib/libft/ft_strchr.c ./my_lib/libft/ft_strrchr.c ./my_lib/libft/ft_strdup.c ./my_lib/libft/ft_strlcat.c ./my_lib/libft/ft_strlcpy.c ./my_lib/libft/ft_strlen.c ./my_lib/libft/ft_strncmp.c ./my_lib/libft/ft_strrchr.c\
	./my_lib/libft/ft_strnstr.c ./my_lib/libft/ft_substr.c ./my_lib/libft/ft_strjoin.c ./my_lib/libft/ft_calloc.c ./my_lib/libft/ft_strtrim.c ./my_lib/libft/ft_split.c\
	./my_lib/libft/ft_strrev.c ./my_lib/libft/ft_strmapi.c ./my_lib/libft/ft_striteri.c


GNL_SRC = ./my_lib/gnl/get_next_line.c ./my_lib/gnl/get_next_line_utils.c

SL_SRC = 	./my_lib/sl_utils/read_map_fd.c\
			./my_lib/sl_utils/replace_in_map.c\
			./my_lib/sl_utils/movement.c\
			./my_lib/sl_utils/directions.c\
			./my_lib/sl_utils/render_player.c\
			./my_lib/sl_utils/map_checker.c\
			./my_lib/sl_utils/enemy_anim.c

sl_OBJS = $(SL_SRC:.c=.o)
libft_OBJS = $(LB_SRC:.c=.o)
gnl_OBJS = $(GNL_SRC:.c=.o)

OBJ = $(gnl_OBJS) $(libft_OBJS) $(sl_OBJS)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) -c $(FLAGS) $(GNL_SRC) $(LB_SRC) $(SL_SRC)
	@ar -rcs $(NAME) $(OBJ)
	$(CC) so_long.c -lmlx -framework OpenGL -framework AppKit $(NAME) -o minecrap

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, all, re