# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 13:29:25 by kbarru            #+#    #+#              #
#    Updated: 2026/01/26 18:02:41 by kbarru           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat
CC = c++
FLAGS = -Wall -Wextra -Werror --std=c++98 -MD -MP -I$(INC_DIR)
DEFINES = -D FORMS -D EX02


INC_DIR = inc/
SRC_DIR = src/
OBJ_DIR = .obj/

SRC = Bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp


OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))
DEPS = $(OBJ:%.o=%.d)

.PHONY: all
all : $(NAME)


.PHONY : clean
clean :
	rm -rf $(OBJ_DIR)

.PHONY : fclean
fclean : clean
	rm -rf $(NAME)

.PHONY : re
re : fclean
	$(MAKE) all

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(DEPS_DIR) :
	mkdir -p $(DEPS_DIR)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) $(DEFINES) -c $< -o $@

-include $(DEPS)
