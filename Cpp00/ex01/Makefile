NAME = phonebook

CC = c++ -g -std=c++98 -I.
CC += -Wall -Wextra -Werror

SRCS = main.cpp Contact.cpp PhoneBook.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(SRCS) -o $(NAME)
	@echo "$(GREEN)[CP00]:\t PROJECT COMPILED$(RESET)"

clean:
	@rm -rf $(NAME)
	@echo "$(RED)[CP00]:\t CLEAN$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[CP00]:\t FCLEAN$(RESET)"

re: fclean all

test: all
	./$(NAME)

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --track-fds=yes ./$(NAME)

#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m