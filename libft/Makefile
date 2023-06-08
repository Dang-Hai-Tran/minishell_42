# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: datran <datran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 12:12:32 by datran            #+#    #+#              #
#    Updated: 2023/06/02 17:37:25 by datran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
				ft_toupper.c ft_itoa_base.c ft_isspace.c\
				ft_printf.c ft_is_argument.c ft_formats.c ft_char_format.c \
				ft_string_format.c ft_pointer_format.c ft_decimal_format.c \
				ft_unsigned_decimal_format.c ft_hexadecimal_format.c \
				ft_upper_case_hexadecimal_format.c ft_percent_format.c ft_input_parser.c \
				get_next_line.c get_next_line_utils.c

B_SRCS	=	ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c

OBJS		=	$(SRCS:%.c=%.o)

BOBJS	=	$(BSRCS:%.c=%.o)

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

RM			=	rm -f

all			:	$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@
			
$(NAME)		:	$(OBJS)
			ar rc $(NAME) $(OBJS)

bonus		:	$(NAME) $(BOBJS)
			ar rc $(NAME) $(BOBJS)

clean		:
			$(RM) $(OBJS) $(BOBJS)

fclean		:	clean
			$(RM) $(NAME)

re			:	fclean all

.PHONY 		: all bonus clean fclean re
