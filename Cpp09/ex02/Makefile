NAME = PmergeMe

CC = c++ -std=c++98 -g -I.
CC += -Wall -Wextra -Werror

SRCS = main.cpp MergeSort.cpp InsertionSort.cpp PmergeMe.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(SRCS) -o $(NAME)
	@echo "$(GREEN)[$(NAME)]:\t PROJECT COMPILED$(RESET)"

clean:
	@echo "$(RED)[$(NAME)]:\t CLEAN$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[$(NAME)]:\t FCLEAN$(RESET)"

re: fclean all

arg = $(shell shuf -i 1-100 -n 100)

test: all
	./$(NAME) $(arg)

val: all
	valgrind ./$(NAME) $(arg)

#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m