# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eutrodri <eutrodri@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/30 15:27:49 by eutrodri      #+#    #+#                  #
#    Updated: 2021/09/10 19:07:19 by eutrodri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = Computor_v1
SRCS = main.cpp v1.cpp

OBJ = main.o v1.o

HEADER = v1.hpp 

O = $(addprefix obj/, $(OBJ))

O_P = mkdir -p obj

OS = $(shell uname)

ifeq ($(OS), Linux)
	CC = g++
else
	CC = clang++
endif

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_RED = $(shell printf "\e[31;5;10m")
COLOR_YELLOW = $(shell printf "\e[33;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFAULT)')
PRINT_CLEAN = $(shell printf '$(COLOR_RED)[ - ]$(COLOR_DEFAULT)')
PROCESS = $(shell printf '$(COLOR_YELLOW)[ › ]$(COLOR_DEFAULT)')


FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

all: $(NAME)

$(NAME) : $(O)
		@echo "$(PROCESS) $(COLOR_YELLOW)COMPILING$(COLOR_DEFAULT)"
		@$(CC) $(FLAGS) -o $(NAME) $(O)
		@echo "$(PRINT_PLUS) $(COLOR_GREEN)Done$(COLOR_DEFAULT)"

obj/%.o : %.cpp $(HEADER)
		@$(O_P)
		@$(CC) $(FLAGS) -c $< -o $@

clean:
		@rm -rf $(O) obj/
		@echo "$(PRINT_CLEAN) $(COLOR_RED)Removed .o files$(COLOR_DEFAULT)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(PRINT_CLEAN) $(COLOR_RED)Removed executable$(COLOR_DEFAULT)"

re: fclean all

.PHONY: all clean fclean re