# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhayward <lhayward@student.42.fr>              +#+  +:+       +#+     #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:32:38 by lhayward            #+#    #+#            #
#    Updated: 2021/01/09 20:11:19 by lhayward           ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

NAME	:=	cub3D


CC		:=	gcc
FLAG	:=	-Wall -Wextra -Werror -o $(NAME)
MIN_F	:=	-lmlx -framework OpenGL -framework AppKit
RM		:=	rm -rf
AR		:=	ar rc


OBJ_D	:=	./obj
INC_D	:=	./include/
MLX_D	:=	mlx_dynamic
LIB_D	:=	libft
GNL_D	:=	get_next_line


INC		:=	cub3D.h
SRCS	:=	cub3d.c parser.c eror.c key.c new_image.c st_8.c valid_map.c raycast2.c cvet.c pars_utils.c sprite_utils.c save.c utils_raycast.c zashita.c ut_sp.c
OBJS	:=	${SRCS:.c=.o}


all:	$(NAME)

${NAME}: ${OBJS} ${INC_D}${INC}
	@make -C $(GNL_D)
	@make -C $(MLX_D)
	cp $(MLX_D)/libmlx.dylib ./
	@make -C $(LIB_D)
	@make bonus -C $(LIB_D)
	@$(CC) $(OBJS) $(LIB_D)/libft.a $(GNL_D)/g_n_l.a  -lmlx -framework OpenGL -framework Appkit $(MLX_D)/libmlx.dylib -o $(NAME)

%.o: %.c ${INC_D}${INC}
	@${CC} ${FLAG} -I${INC_D} -c $< -o $@

clean:		
	@make clean -C $(MLX_D)
	@make clean -C $(LIB_D)
	@make clean -C $(GNL_D)
	@rm -f ${OBJS}

fclean:		clean
	@make fclean -C $(LIB_D)
	@make fclean -C $(GNL_D)
	@rm -f ${NAME}

re:     fclean all
