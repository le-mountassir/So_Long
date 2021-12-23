# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahel-mou <ahel-mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 10:17:43 by ahel-mou          #+#    #+#              #
#    Updated: 2021/12/22 17:39:19 by ahel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

mand_SRC =	./mand/sl_utils/read_map_fd.c\
			./mand/sl_utils/replace_in_map.c\
			./mand/sl_utils/movement.c\
			./mand/sl_utils/directions.c\
			./mand/sl_utils/render_player.c\
			./mand/sl_utils/map_checker.c\
			./mand/my_lib/libft/ft_bzero.c ./mand/my_lib/libft/ft_memcpy.c ./mand/my_lib/libft/ft_memchr.c ./mand/my_lib/libft/ft_memmove.c ./mand/my_lib/libft/ft_memset.c ./mand/my_lib/libft/ft_memcmp.c\
			./mand/my_lib/libft/ft_strchr.c ./mand/my_lib/libft/ft_strrchr.c ./mand/my_lib/libft/ft_strdup.c ./mand/my_lib/libft/ft_strlcat.c ./mand/my_lib/libft/ft_strlcpy.c ./mand/my_lib/libft/ft_strlen.c ./mand/my_lib/libft/ft_strncmp.c ./mand/my_lib/libft/ft_strrchr.c\
			./mand/my_lib/libft/ft_strnstr.c ./mand/my_lib/libft/ft_substr.c ./mand/my_lib/libft/ft_strjoin.c ./mand/my_lib/libft/ft_calloc.c ./mand/my_lib/libft/ft_strtrim.c ./mand/my_lib/libft/ft_split.c\
			./mand/my_lib/libft/ft_strrev.c ./mand/my_lib/libft/ft_itoa.c\
			./mand/my_lib/gnl/get_next_line.c ./mand/my_lib/gnl/get_next_line_utils.c
			
bonus_SRC = ./bonus/sl_utils/read_map_fd.c\
			./bonus/sl_utils/replace_in_map.c\
			./bonus/sl_utils/movement.c\
			./bonus/sl_utils/directions.c\
			./bonus/sl_utils/render_player.c\
			./bonus/sl_utils/map_checker.c\
			./bonus/sl_utils/enemy_re_render.c\
			./bonus/my_lib/libft/ft_bzero.c ./bonus/my_lib/libft/ft_memcpy.c ./bonus/my_lib/libft/ft_memchr.c ./bonus/my_lib/libft/ft_memmove.c ./bonus/my_lib/libft/ft_memset.c ./bonus/my_lib/libft/ft_memcmp.c\
			./bonus/my_lib/libft/ft_strchr.c ./bonus/my_lib/libft/ft_strrchr.c ./bonus/my_lib/libft/ft_strdup.c ./bonus/my_lib/libft/ft_strlcat.c ./bonus/my_lib/libft/ft_strlcpy.c ./bonus/my_lib/libft/ft_strlen.c ./bonus/my_lib/libft/ft_strncmp.c ./bonus/my_lib/libft/ft_strrchr.c\
			./bonus/my_lib/libft/ft_strnstr.c ./bonus/my_lib/libft/ft_substr.c ./bonus/my_lib/libft/ft_strjoin.c ./bonus/my_lib/libft/ft_calloc.c ./bonus/my_lib/libft/ft_strtrim.c ./bonus/my_lib/libft/ft_split.c\
			./bonus/my_lib/libft/ft_strrev.c ./bonus/my_lib/libft/ft_itoa.c\
			./bonus/my_lib/gnl/get_next_line.c ./bonus/my_lib/gnl/get_next_line_utils.c

mand_OBJS = $(mand_SRC:.c=.o)
bonus_OBJS = $(bonus_SRC:.c=.o)

b_OBJ = $(bonus_OBJS)
m_OBJ = $(mand_OBJS)

b_header = ./bonus/bonus_libft.h
m_header = ./mand/mand_libft.h

all: b m

b : $(b_OBJ) $(b_header)
	@$(CC) -c $(FLAGS) $(bonus_SRC)
	@ar -rcs $(NAME) $(b_OBJ)
	$(CC) ./bonus/so_long.c -lmlx -framework OpenGL -framework AppKit $(NAME) -o so_long_bonus

m : $(m_OBJ) $(m_header)
	@$(CC) -c $(FLAGS) $(mand_SRC)
	@ar -rcs $(NAME) $(m_OBJ)
	$(CC) ./mand/so_long.c -lmlx -framework OpenGL -framework AppKit $(NAME) -o so_long
	
clean:
	find . -name "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, all, re