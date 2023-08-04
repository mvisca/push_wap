# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 18:40:44 by mvisca-g          #+#    #+#              #
#    Updated: 2023/08/04 21:29:44 by mvisca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------#
#	FORMAT			#
#-------------------#

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
NC				:= \033[0m

#-------------------#
#	TARGET			#
#-------------------#

NAME			:=	push_swap

#-------------------#
#	INGREDIENTS		#
#-------------------#

PS_INC_DIR		:=	include
PS_INCLUDE		:=	push_swap.h

LIB_DIR			:=	libft
LIB_INC_DIR		:=	libft/include
LIB_TGT			:=	libft/libft.a

SRCS_DIR		:=	src
OBJS_DIR		:=	.build

FILES			:=	push_swap.c							\
						push_swap_commands.c			\
						push_swap_debug.c				\
						push_swap_list_tools.c			\
						push_swap_mem_utils.c			\
						push_swap_parse.c				\
						push_swap_sort.c				\
						push_swap_sort_utils_a.c		\
						push_swap_sort_utils_b2a.c		\
						push_swap_sort_utils_b.c		\
						push_swap_sort_utils_long.c		\
						push_swap_sort_utils_three.c	\
						push_swap_sort_utils_five.c		\
						push_swap_sort_utils_two.c

SRCS			:=	$(addprefix $(SRCS_DIR)/, $(FILES))

OBJS			:=	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

DEPS			:=	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.d))

#-------------------#
#	UTILS			#
#-------------------#

CC				:=	gcc #-g -fsanitize=address

CFLAGS			:=	-Wall -Wextra -Werror -MMD


DIR_DUP			=	mkdir -p $(@D)

MAKEFLAGS		+=	--no-print-directory
RM				:=	rm -r -f

#-------------------#
#	RECIPES			#
#-------------------#

all: $(NAME)

$(NAME): callforlib $(OBJS)
	@echo "$(YELLOW)Compiling $(RED)$@ $(YELLOW)ready! $(NC)"
	$(CC) $(CFLAGS) -L./$(LIB_DIR) -I./$(LIB_INC_DIR) -I./$(PS_INC_DIR) $(OBJS) -lft -o $(@)
-include $(DEPS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile 
	@$(DIR_DUP)
	@echo "$(GREEN)Creating... $(NC) $(notdir $@)"
	$(CC) ${CFLAGS} -I./$(LIB_INC_DIR) -I./$(PS_INC_DIR) -L./$(LIB_DIR) -lft -c $< -o $@
-include $(DEPS)

$(LIB_TGT):
	@echo "Compling LIBFT"
	@$(MAKE) -C $(LIB_DIR)

done:
	 @touch .done
	 
test:
	echo "$(SRCS:%.c)"

clean:
	@echo "$(RED)Deleting objects for... $(NC)$(NAME) *.o *.d $(RED)>> 🗑️$(NC)"
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Deleting... $(NC)$(NAME) $(RED)>> 🗑️$(NC)"
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

callforlib:
	@$(MAKE) -C $(LIB_DIR)

ndad:
	@echo "Making . make"
	@$(MAKE) -C . $(NAME)

.PHONY: clean fclean all test
