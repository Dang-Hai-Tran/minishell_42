PROJECT_NAME := Libft
BIN_NAME  := libft.a
CC        := gcc
AR        := ar rcs
ROOTDIR   := ../
SRCDIR    := srcs
HEADERDIR := incs
LIBDIR    := lib
BUILDDIR  := build
BINDIR    := bin
TARGET    := $(BINDIR)/$(BIN_NAME)
SOURCES   := $(shell find $(SRCDIR) -type f -name *.c*)
HEADERS   := $(shell find $(HEADERDIR) -type f -name *.h*)
LIB       := 
LIBS      := $(shell find $(ROOTDIR) -type f -name *.a*)
OBJECTS   := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .o,$(basename $(SOURCES))))
DEPS      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .d,$(basename $(SOURCES))))
CFLAGS    := -Wall -Werror -Wextra
INC       := -Iincs -Isrcs

all: debug
debug: CFLAGS += -g
debug: $(TARGET)
release: $(TARGET)
release: CFLAGS += -O3

GREEN=`tput setaf 2`
RED=`tput setaf 1`
RESET=`tput sgr0`

define print_green
	@echo "$(GREEN)$(1)$(RESET)"
endef

define print_red
	@echo "$(RED)$(1)$(RESET)"
endef

all: $(TARGET)

clean:
	$(call print_red,"Deleting the $(BUILDDIR) directory in $(PROJECT_NAME)...")
	@rm -rf $(BUILDDIR) 

fclean: clean
	$(call print_red,"Deleting the $(BINDIR) directory in $(PROJECT_NAME)...")
	@rm -rf $(BINDIR)

re: fclean all

$(TARGET): $(BINDIR) $(BUILDDIR) $(OBJECTS)
	$(call print_green,"Linking object files...")
	@$(AR) $(TARGET) $(OBJECTS)
	$(call print_green,"$(TARGET) has been created!")

$(BUILDDIR) :
	@mkdir -p $(BUILDDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.c*
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INC) -M $< -MT $@ > $(@:.o=.td)
	@cp $(@:.o=.td) $(@:.o=.d); 
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(@:.o=.td) >> $(@:.o=.d); 
	@rm -f $(@:.o=.td)


-include $(DEPS)

.PHONY: clean fclean all
