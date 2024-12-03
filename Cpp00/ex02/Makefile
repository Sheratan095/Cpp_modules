NAME = jobofmydreams

CC = c++ -std=c++98 -g
CC += -Wall -Wextra -Werror -I.

SRCS = tests.cpp Account.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(SRCS) -o $(NAME)
	@echo "$(GREEN)[$(NAME)]:\t PROJECT COMPILED$(RESET)"

clean:
	@rm -rf $(NAME)
	@echo "$(RED)[$(NAME)]:\t CLEAN$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[$(NAME)]:\t FCLEAN$(RESET)"

re: fclean all

ARGS =      dsadasa      

test: all
	./$(NAME) $(ARGS)

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --track-fds=yes ./$(NAME) $(ARGS)

#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m