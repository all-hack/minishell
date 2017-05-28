# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 00:08:23 by obelange          #+#    #+#              #
#    Updated: 2016/11/12 00:08:25 by obelange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

RUN  = a.out

FILE += ft_printf ft_printf_flow ft_printf_format_parsing

FILE += ft_printf_symdet_prec ft_printf_symdet_flags ft_printf_symdet_mfw \
ft_printf_symdet_length ft_printf_symdet_conv

FILE += ft_printf_dfree_hack ft_printf_free_struct ft_printf_init_struct \
ft_printf_reset_struct

FILE += ft_printf_proc_flags ft_printf_proc_setchar ft_printf_proc_precision \
ft_printf_proc_mfieldwidth

FILE += ft_printf_app_conv ft_printf_app_precision ft_printf_app_mfieldwidth 

FILE += ft_printf_flag_space ft_printf_flag_plus ft_printf_flag_minus \
ft_printf_flag_0 ft_printf_app_flags ft_printf_flag_hash 

FILE += ft_printf_chng_char ft_printf_chng_uchar ft_printf_chng_short \
ft_printf_chng_ushort ft_printf_chng_uint ft_printf_chng_int \
ft_printf_chng_long ft_printf_chng_ulong ft_printf_chng_size_t \
ft_printf_chng_longlong ft_printf_chng_ulonglong ft_printf_chng_intmax_t \
ft_printf_chng_uintmax_t ft_printf_chng_wchar_t

FILE += ft_printf_get_b ft_printf_get_c ft_printf_get_cap_c ft_printf_get_d \
ft_printf_get_i ft_printf_get_u ft_printf_get_o ft_printf_get_x \
ft_printf_get_p ft_printf_get_s ft_printf_get_cap_s ft_printf_get_percent \
ft_printf_get_cap_x ft_printf_get_cap_d ft_printf_get_cap_u \
ft_printf_get_cap_o

FILE += ft_printf_atoi ft_printf_itoa_base ft_printf_itoa_binary \
ft_printf_itoa

FILE += ft_printf_1chr_nsym ft_printf_nchr_1sym ft_printf_stric \
ft_printf_strchri

FILE += ft_printf_fstrinsert ft_printf_frmvdup ft_printf_strinsert \
ft_printf_strupper ft_printf_fstrmcat_conv ft_printf_strcpy \
ft_printf_fstrappend ft_printf_shiftstr ft_printf_fstrmcat \
ft_printf_putstr ft_printf_strdel  ft_printf_strcmp ft_printf_strlen \
ft_printf_strmcat ft_printf_strsub ft_printf_strncpy ft_printf_strcat \
ft_printf_strncat ft_printf_strnew ft_printf_strdup \



# FILE += main



W_FILES = $(FILE) fr_printf_getarray_widechar
FILES += $(FILE) fr_printf_getarray 

S_PATH = src/
H_PATH = include/
B_PATH = build/

SRC_PRE = $(addprefix $(S_PATH), $(FILES))
SRC = $(addsuffix .c, $(SRC_PRE)) $(SYMDET_SRC)



C_OBJ_PRE = $(addprefix $(B_PATH), $(FILES))
C_OBJ = $(addsuffix .o, $(C_OBJ_PRE)) $(SYMDET_OBJ)


WSRC_PRE = $(addprefix $(S_PATH), $(W_FILES))
WSRC = $(addsuffix .c, $(WSRC_PRE)) $(SYMDET_SRC)

WC_OBJ_PRE = $(addprefix $(B_PATH), $(W_FILES))
WC_OBJ = $(addsuffix .o, $(WC_OBJ_PRE))  $(SYMDET_OBJ)

C_FLAGS = -Wall -Werror -Wextra
DEV_FLAGS = $(C_FLAGS) -fsanitize=address
LEAK_F = $(C_FLAGS) $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl
ifdef ALLOCWRAP
	C_FLAGS += $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl
endif 


.PHONY : all clean fclean dev re

all : $(NAME)

$(NAME): build $(C_OBJ)
	@ar rc $(NAME) $(C_OBJ)

run : fclean build $(C_OBJ)
	gcc $(C_FLAGS) -o $(RUN) $(C_OBJ) -I ./include && ./$(RUN)

leak : build $(C_OBJ)
	gcc $(LEAK_F) -o $(RUN) $(C_OBJ) -I ./include && ./$(RUN)

wrun : fclean build $(WC_OBJ)
	gcc $(C_FLAGS) -o $(RUN) $(WC_OBJ) -I ./include && ./$(RUN)

dev : fclean build $(C_OBJ)
	gcc $(DEV_FLAGS) -o $(RUN) $(C_OBJ) -I ./include && ./$(RUN)

$(B_PATH)%.o: $(S_PATH)%.c		
	@gcc -c $< -o $@ -I ./include

w : build $(WC_OBJ)
	ar rc $(NAME) $(WC_OBJ)

build : 
	@mkdir -p build

clean :
	@rm -rf build

fclean : clean
	@rm -f $(NAME) $(RUN)

re : fclean all
