# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 11:25:58 by obelange          #+#    #+#              #
#    Updated: 2016/10/22 17:26:22 by obelange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libhashtbl.a

RUN = a.out

S_PATH = src/
B_PATH = build/
H_PATH = include/


FILES = generic_helper

FILES += t_hash_infa t_hash_helper

FILES += t_node_infa

# FILES += main 


OBJ = $(addprefix $(B_PATH), $(addsuffix .o, $(FILES)))

FLAGS = -Wall -Werror -Wextra -g
DEVF = $(FLAGS) -fsanitize=address
LEAKF = $(FLAGS) $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl

ifdef ALLOCWRAP
	C_FLAGS += $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl
endif 

.PHONY: all fclean clean run leak

all : $(NAME)

$(NAME): build $(OBJ)
	@ar rc $(NAME) $(OBJ)

run : fclean build $(OBJ)
	@gcc $(FLAGS) -o $(RUN) $(OBJ) -I ./include && ./$(RUN)

leak : build $(OBJ)
	@gcc $(LEAK_F) -o $(RUN) $(OBJ) -I ./include && ./$(RUN)

dev : fclean build $(OBJ)
	@gcc $(DEV_FLAGS) -o $(RUN) $(OBJ) -I ./include && ./$(RUN)

$(B_PATH)%.o: $(S_PATH)%.c		
	@gcc -c $< -o $@ -I ./include

build : 
	@mkdir -p build

clean :
	@rm -rf build

fclean : clean
	@rm -f $(NAME) $(RUN)

re : fclean all
