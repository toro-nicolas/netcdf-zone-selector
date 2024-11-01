##
## SEAGNAL PROJECT, 2024
## netcdf-zone-selector
## File description:
## The main Makefile of our project
##

NAME		=	netcdf-zone-selector

CC		=	g++

BUILDDIR 	=	./build
SRCDIR		=	./src

SRCS		=	$(shell find $(SRCDIR) -path ./tests -prune -o -type f -name "*.cc" -print)

OBJS     	=	$(patsubst ./%.cc, $(BUILDDIR)/%.o, $(SRCS))

CFLAGS		=	-Werror -Wextra -I./include/
DEBUGFLAGS	=	-g3 -DDEBUG_MODE
OPTIMIZEFLAGS	=	-O3

LDFLAGS 	=	-lnetcdf -lproj -lm -lboost_program_options

.PHONY: all create-build debug clean fclean re

all: create-build $(BUILDDIR) $(NAME)
	@echo -e "\033[1;33m$(NAME) compiled.\033[0m"

create-build:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: ./%.cc
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS)
debug: OPTIMIZEFLAGS =
debug: all

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	@rm -rf $(BUILDDIR)
	@echo -e "\033[1;31mAll .o deleted.\033[0m"

fclean: clean
	@rm -rf vgcore*
	@rm -rf *.log
	@rm -rf $(NAME)
	@echo -e "\033[1;31mProject cleaned.\033[0m"

re:	fclean all

re_debug: fclean debug

valgrind: fclean debug
	@echo -e "\033[0;36mExecuting valgrind...\033[0m"
	@valgrind $(VALGRINDFLAGS) ./$(NAME) 2> $(OUTPUT)

# Documentation
doc:
	@mkdir -p docs/html
	@doxygen Doxyfile
	@echo -e "\033[1;33mDocumentation generated.\033[0m"
	@google-chrome docs/html/index.html
