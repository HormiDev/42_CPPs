# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 02:49:13 by ide-dieg          #+#    #+#              #
#    Updated: 2025/06/21 18:02:43 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

SRCS = main.cpp \
		megapho

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): ide-dieg cpp_title $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)...$(GREEN)"
	@$(CC) $(CFLAGS) -o $@ $(OBJS)
	@tput cuu1 && tput el
	@echo "$(GREEN)Compilation complete!$(NC)"

%.o: %.cpp
	@echo "$(YELLOW)Bounding $< to object file...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@tput cuu1 && tput el
	@echo "$(GREEN)Object file $< created!$(NC)"

clean:
	@echo "$(RED)Cleaning up object files...$(NC)"
	@rm -f $(OBJS)
	@tput cuu1 && tput el
	@echo "$(GREEN)Object files cleaned!$(NC)"

fclean: clean
	@echo "$(RED)Cleaning up $(NAME)...$(NC)"
	@rm -f $(NAME)
	@tput cuu1 && tput el
	@echo "$(GREEN)All clean!$(NC)"	

re: fclean all

ROJO = \033[0;31m
NC = \033[0m
NARANJA = \033[0;33m
AZUL = \033[0;34m
VERDE = \033[0;32m

ide-dieg:
	@echo "$(ROJO)██╗██████╗ ███████╗    ██████╗ ██╗███████╗ ██████╗ $(AZUL)         ██╗  ██╗██████╗ "
	@echo "$(ROJO)██║██╔══██╗██╔════╝    ██╔══██╗██║██╔════╝██╔════╝ $(AZUL)         ██║  ██║╚════██╗"
	@echo "$(ROJO)██║██║  ██║█████╗█████╗██║  ██║██║█████╗  ██║  ███╗$(AZUL)         ███████║ █████╔╝"
	@echo "$(ROJO)██║██║  ██║██╔══╝╚════╝██║  ██║██║██╔══╝  ██║   ██║$(AZUL)         ╚════██║██╔═══╝ "
	@echo "$(ROJO)██║██████╔╝███████╗    ██████╔╝██║███████╗╚██████╔╝$(AZUL)              ██║███████╗"
	@echo "$(ROJO)╚═╝╚═════╝ ╚══════╝    ╚═════╝ ╚═╝╚══════╝ ╚═════╝ $(AZUL)              ╚═╝╚══════╝"
	@echo "$(NARANJA)██╗  ██╗ ██████╗ ██████╗ ███╗   ███╗██╗██████╗ ███████╗██╗   ██╗$(VERDE)       ██╗  "
	@echo "$(NARANJA)██║  ██║██╔═══██╗██╔══██╗████╗ ████║██║██╔══██╗██╔════╝██║   ██║$(VERDE)   ██╗ ╚═██╗"
	@echo "$(NARANJA)███████║██║   ██║██████╔╝██╔████╔██║██║██║  ██║█████╗  ██║   ██║$(VERDE)   ╚═╝   ██║"
	@echo "$(NARANJA)██╔══██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║  ██║██╔══╝  ╚██╗ ██╔╝$(VERDE)   ██╗   ██║"
	@echo "$(NARANJA)██║  ██║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██████╔╝███████╗ ╚████╔╝ $(VERDE)   ╚═╝ ██╔═╝ "
	@echo "$(NARANJA)╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═════╝ ╚══════╝  ╚═══╝  $(VERDE)       ╚═╝  $(NC)"

cpp_title:
	@echo " _  _  ____  ___   __   ____  _  _   __   __ _  ____ "
	@echo "( \/ )(  __)/ __) / _\ (  _ \/ )( \ /  \ (  ( \(  __)"
	@echo "/ \/ \ ) _)( (_ \/    \ ) __/) __ ((  O )/    / ) _) "
	@echo "\_)(_/(____)\___/\_/\_/(__)  \_)(_/ \__/ \_)__)(____)"

.PHONY: all clean fclean re ide-dieg cpp_title