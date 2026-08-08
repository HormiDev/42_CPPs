# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/19 01:53:22 by ide-dieg          #+#    #+#              #
#    Updated: 2026/08/08 13:59:43 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Bureaucrat

SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp


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
	@echo " ____  _  _  ____  ____   __   _  _   ___  ____   __  ____       __    __   "
	@echo "(  _ \/ )( \(  _ \(  __) / _\ / )( \ / __)(  _ \ / _\(_  _)     /  \  /  \  "
	@echo " ) _ () \/ ( )   / ) _) /    \) \/ (( (__  )   //    \ )(  ____(  0 )(_/ /  "
	@echo "(____/\____/(__\_)(____)\_/\_/\____/ \___)(__\_)\_/\_/(__)(____)\__/  (__)  "

.PHONY: all clean fclean re ide-dieg cpp_title
