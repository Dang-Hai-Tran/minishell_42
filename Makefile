PROJECT_NAME := Minishell
BIN_NAME  := minishell
CC        := gcc
ROOTDIR   := .
SRCDIR    := srcs
HEADERDIR := incs
LIBDIR    := lib
BUILDDIR  := build
BINDIR    := bin
TARGET    := $(BINDIR)/$(BIN_NAME)
SOURCES   := $(shell find $(SRCDIR) -type f -name '*.c' | grep -v tests)
HEADERS   := $(shell find $(HEADERDIR) -type f -name '*.h' | grep -v tests)
LIB       := -L./lib -lft -lreadline -lncurses
LIBS      := $(shell find $(ROOTDIR) -type f -name '*.a')
OBJECTS   := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .o,$(basename $(SOURCES))))
DEPS      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .d,$(basename $(SOURCES))))
CFLAGS    := -Wall -Werror -Wextra -g
INC       := -Iincs -Isrcs

GREEN=`tput setaf 2`
RED=`tput setaf 1`
RESET=`tput sgr0`

define print_green
	@echo "$(GREEN)$(1)$(RESET)"
endef

define print_red
	@echo "$(RED)$(1)$(RESET)"
endef

all: libs $(BINDIR) $(BUILDDIR) $(OBJECTS)
	$(call print_green,"Linking object files...")
	@$(CC) -o $(TARGET) $(OBJECTS) $(LIB)
	$(call print_green,"$(TARGET) has been created!")

lib/$(PROJECT_NAME).flag: $(LIBS)
	@make -C libft
	@find . -type f -name *.a* -exec mv -t lib {} +
	@touch $@
	@rm -rf libft/$(BINDIR)
libs: $(LIBDIR) lib/$(PROJECT_NAME).flag

clean:
	$(call print_red,"Deleting the $(BUILDDIR) directory in $(PROJECT_NAME)...")
	@rm -rf $(BUILDDIR) 
	@make -C libft clean

fclean: clean
	$(call print_red,"Deleting the $(BINDIR) directory in $(PROJECT_NAME)...")
	@rm -rf $(BINDIR)

re: fclean all

prod: fclean
	$(call print_red,"Deleting the $(LIBDIR) directory in $(PROJECT_NAME)...")
	@rm -rf $(LIBDIR)

$(LIBDIR) :
	@mkdir -p $(LIBDIR)

$(BUILDDIR) :
	@mkdir -p $(BUILDDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INC) -M $< -MT $@ > $(@:.o=.td)
	@cp $(@:.o=.td) $(@:.o=.d); 
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(@:.o=.td) >> $(@:.o=.d); 
	@rm -f $(@:.o=.td)

-include $(DEPS)

.PHONY: clean fclean all libs

# Outputs valgrind to the terminal
# valgrind --log-file=logs/val.log --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=.ignore_readline_leaks.supp ./bin/minishell

# Outputs valgrind debug logs to a log file
# valgrind --log-file=logs/val.log --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=.ignore_readline_leaks.supp ./bin/minishell
# Remove all comments in a file : \/\*(?:[^*]|[\r\n]|(\*+(?:[^*/]|[\r\n])))*\*\/

# Sur Linux
# lib/$(PROJECT_NAME).flag: $(LIBS)
# 	@make -C ../gnl
# 	@make -C ../libft
# 	@find ../ -type f -name *.a* -exec mv -t ../minishell/lib {} +
# 	@touch $@
# 	@rm -rf ../gnl/$(BINDIR)
# 	@rm -rf ../libft/$(BINDIR)
# libs: $(LIBDIR) lib/$(PROJECT_NAME).flag

# Sur Mac
# lib/$(PROJECT_NAME).flag: $(LIBS)
# 	@make -C ../gnl
# 	@make -C ../libft
# 	@find ../ -type f -name *.a* -exec gmv -t ../minishell/lib {} +
# 	@touch $@
# 	@rm -rf ../gnl/$(BINDIR)
# 	@rm -rf ../libft/$(BINDIR)
# libs: $(LIBDIR) lib/$(PROJECT_NAME).flag
