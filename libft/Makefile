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

NAME = libft.a

S_PATH = src/
B_PATH = build/
H_PATH = include/

FILES = ft_strlen ft_toupper ft_tolower ft_strclr ft_strcpy ft_strncpy\
ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strcmp ft_strncmp\
ft_strequ ft_strnequ ft_strstr ft_strnstr ft_memset ft_bzero ft_memcpy\
ft_memccpy ft_memmove ft_memchr ft_memcmp ft_isalpha ft_isdigit ft_isalnum\
ft_isascii ft_isprint ft_putchar ft_putchar_fd ft_putstr ft_putstr_fd\
ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_atoi ft_itoa ft_memalloc\
ft_strnew ft_memdel ft_strdel ft_striter ft_striteri ft_strmap ft_strmapi\
ft_strdup ft_strsub ft_strjoin ft_strtrim ft_strsplit 

FILES += ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap
FILES += ft_stri_head ft_stri_tail ftsd ft_strdfree ft_isnt32

# get_next_line
FILES += ft_stric ft_strmcat get_next_line

# ft_printf
FILES += ft_1chr_nsym ft_intmax_atoi ft_fstrappend ft_fstrinsert ft_fstrmcat \
ft_itoa_base ft_nchr_1sym ft_shiftstr ft_strchri

# ft_ls
FILES += ft_fstrdup ft_fstrmcatf ft_strcut_c0 ft_strlist_add \
ft_strlist_build ft_strlist_del ft_strlist_findindex ft_strlist_len \
ft_strlist_minus ft_strlist_print ft_strlist_remove ft_strmcatf \
ft_strsearch_ov

RUN_FILES += $(FILES) main

OBJ = $(addprefix $(B_PATH), $(addsuffix .o, $(FILES)))
ROBJ = $(addprefix $(B_PATH), $(addsuffix .o, $(RUN_FILES)))

SRC = $(addprefix $(S_PATH), $(addsuffix .c, $(FILES)))

HDR = libft.h

FLAGS = -Wall -Werror -Wextra

.PHONY: all fclean clean fsan run re norm test build


all : $(NAME)

$(NAME): build $(OBJ)
	@ar rc $(NAME) $(OBJ)

run: fclean build $(ROBJ)
	@gcc $(FLAGS) -o a.out $(ROBJ) -I ./include && ./a.out

# $(OBJ) :  build
# 	@gcc -c $(SRC) -I ./include

fsan : fclean build $(ROBJ)
	@gcc $(FLAGS) -fsanitize=address -o a.out $(ROBJ) -I ./include

$(B_PATH)%.o: $(S_PATH)%.c
	@gcc -c $< -o $@ -I ./include

build : 
	@mkdir -p build

norm : 
	norminette

clean :	
	@rm -rf build

fclean : clean
	@rm -f $(NAME) a.out

re : fclean all
