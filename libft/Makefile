# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhayward <lhayward@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:32:38 by lhayward            #+#    #+#              #
#    Updated: 2020/12/26 13:50:21 by lhayward           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror

RM		=	rm -rf

AR		=	ar rc

SRC_D	=	./src/

OBJ_D	=	./obj

INC_D	=	./include/

INC		=	libft.h

SRCS	=	$(addprefix ${SRC_D}, ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c \
			ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ) 

SRCS1	=	$(addprefix ${SRC_D}, ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c )

OBJS	=	${SRCS:.c=.o}

OBJS1	=	${SRCS1:.c=.o}


all:		$(NAME)
	
${NAME}: ${OBJS} ${INC_D}${INC}
	@${AR} ${NAME} ${OBJS}
	@ranlib ${NAME}

bonus:		${OBJS1}
	@${AR} ${NAME} ${OBJS1}
	@ranlib ${NAME}

%.o: %.c
	@${CC} ${FLAG} -I ${INC_D} -c $< -o $@

clean:		
	@rm -f ${OBJS} ${OBJS1}

fclean:		clean
	@rm -f ${NAME}

re:     fclean all
