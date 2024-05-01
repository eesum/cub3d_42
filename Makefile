# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 18:38:57 by seohyeki          #+#    #+#              #
#    Updated: 2024/05/01 19:22:27 by sumilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = libft.a
LIBFT_DIR = libft
MLX = libmlx.a
MLX_DIR = .mlx
INC_DIR = include
P_SRCS = parse/parse_info.c \ 
		 parse/ft_lst_trim.c \
		 parse/parse_map_utils.c \
		 parse/parsemap_.c \
		 parse/map_valid_chk.c
E_SRCS = main.c \
		 init.c
U_SRCS = util.c
P_OBJS = $(P_SRCS:.c=.o)
E_OBJS = $(E_SRCS:.c=.o)
U_OBJS = $(U_SRCS:.c=.o)
P_DEPS = $(P_SRCS:.c=.d)
E_DEPS = $(E_SRCS:.c=.d)
U_DEPS = $(U_SRCS:.c=.d)
A_OBJS = $(P_OBJS) $(E_OBJS) $(U_OBJS)
A_DEPS = $(P_DEPS) $(E_DEPS) $(U_DEPS)
CFLAGS = -Wall -Wextra -Werror -MMD -MP
LIBINC = -lmlx -Lmlx -lft -Llibft -framework OpenGL -framework Appkit

all : $(NAME)

$(NAME) : $(A_OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	cc $(CFLAGS) $(LIBINC) -o $@ $^

-include $(A_DEPS)

%.o : %.c
	cc -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(INC_DIR) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(A_OBJS) $(A_DEPS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all
	
.PHONY : all clean fclean re
