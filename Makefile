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

NAME = minishell

S_PATH = src/
B_PATH = build/
H_PATH = include/
LIBFT_PATH = libft
PRINTF_PATH = ft_printf
HASH_PATH = hashtbl

FILES = msh_helper

FILES += t_cmdin_infa t_cmdin_new_words

FILES += t_env_infa t_env_helper

FILES += builtins_env builtins_error builtins_function

FILES += 

FILES += 

FILES += 

FILES += 

FILES += 

FILES += main 

OBJ = $(addprefix $(B_PATH), $(addsuffix .o, $(FILES)))

LIB_COMP = -L$(LIBFT_PATH) -lft -I$(LIBFT_PATH) -L$(PRINTF_PATH) -lftprintf -I$(PRINTF_PATH) -L$(HASH_PATH) -lhashtbl -I$(HASH_PATH)

FLAGS = -Wall -Werror -Wextra
DEVF = $(FLAGS) -fsanitize=address
LEAKF = $(FLAGS) $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl

ifdef ALLOCWRAP
	C_FLAGS += $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl
endif 

.PHONY: all fclean clean run leak

all : $(NAME)

$(NAME) : $(B_PATH) $(OBJ) libft.a libftprintf.a libhashtbl.a 
	@echo ""
	@echo ""
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_COMP)

run : fclean $(B_PATH) $(OBJ) libft.a libftprintf.a libhashtbl.a
	@echo "\x1b[31mrun is turned on\x1b[36m"
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_COMP) && printf "\x1b[37m" && ./$(NAME)

dev : fclean $(B_PATH) $(OBJ) libft.a libftprintf.a libhashtbl.a
	gcc $(DEVF) -o $(NAME) $(OBJ) $(LIB_COMP)

leak : $(B_PATH) $(OBJ) libft.a  libftprintf.a libhashtbl.a
	@echo "\x1b[31malloc wrap is turned on\x1b[36m"
	gcc $(LEAKF) -o $(NAME) $(OBJ) $(LIB_COMP)

leaks: re
	@ osascript -e 'tell application "iTerm2" to activate' -e '\
		tell application "System Events" to tell process "iTerm2" to keystroke "D" using command down' -e 'tell application "System Events" to tell process "iTerm" to keystroke "while true ;do clear; leaks $(NAME); sleep 2 ;done"' -e 'tell application "System Events" to tell process "iTerm" to key code 52'

libft.a : 
	@printf "\x1b[32m \ncompiling libft.... \x1b[36m"
	@$(MAKE) -C $(LIBFT_PATH) all

libftprintf.a :
	@printf "\x1b[32m \ncompiling printf.... \x1b[36m"
	@$(MAKE) -C $(PRINTF_PATH) all

libhashtbl.a :
	@printf "\x1b[32m \ncompiling hashtbl.... \x1b[36m"
	@$(MAKE) -C $(HASH_PATH) all

$(B_PATH) :
	@printf "\x1b[32m \nbuilding objects.....\n\x1b[33m"
	@mkdir build

$(B_PATH)%.o : $(S_PATH)%.c
	gcc -c $< -o $@ -I ./$(LIBFT_PATH)/$(H_PATH) -I ./$(H_PATH) -I ./$(PRINTF_PATH)/$(H_PATH) -I ./$(HASH_PATH)/$(H_PATH)
	
clean : 
	@rm -rf build
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(PRINTF_PATH) clean
	@$(MAKE) -C $(HASH_PATH) clean

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(PRINTF_PATH) fclean
	@$(MAKE) -C $(HASH_PATH) fclean

re : fclean all


