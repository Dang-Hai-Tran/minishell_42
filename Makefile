NAME = minishell
CC = gcc
FLAGS = -Werror -Wextra -Wall -g
SRCDIR = srcs/
BUILDDIR  := build/
SRCS = $(shell find $(SRCDIR) -type f -name '*.c')
OBJS = $(patsubst $(SRCDIR)%,$(BUILDDIR)%,$(addsuffix .o,$(basename $(SRCS))))

LIB = libft/libft.a
LIBFLAGS = -Llibft -lft
RLFLAGS = -lreadline -Iincs/

RM = rm -rf

all : $(NAME)

$(BUILDDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@ $(RLFLAGS)

$(NAME) : $(OBJS) $(LIB)
	$(CC) $(FLAGS) $(OBJS) $(LIBFLAGS) -o $@ $(RLFLAGS)

$(LIB) :
	make -C libft

clean :
	make -C libft clean
	$(RM) $(BUILDDIR)

fclean : clean
	$(RM) $(LIB)
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
