# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongklee <dongklee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/30 20:19:59 by easternstar       #+#    #+#              #
#    Updated: 2021/05/06 18:45:19 by dongklee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap checker
PUSHSWAP	= push_swap
CHECKER		= checker

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

_CYON_		= \033[36m
_GREEN_		= \033[32m
_YELLOW_	= \033[33m
_END_		= \033[0m

HEADER		= ./srcs/push_swap.h

UTIL_FILE	= utils_func \
			utils_pivot \
			utils_libft \
			utils_gnl \
			utils_sort \
			utils_parse \
			utils_exception_error \
			sort_under_three \
			sort_under_five \
			solve \
			solve_ops_cnt \
			solve_term_return \
			rule_swap \
			rule_rotate \
			rule_rev_rotate \
			rule_push \
			get_next_line \
			game_rule \
			check_sorted \
			argv_to_stack

PSSW_MAIN	= main_push_swap
CHCK_MAIN	= main_checker

DIR_SRCS	= ./srcs/
DIR_OBJS	= ./objs/

UTIL_SRCS	= $(addprefix $(DIR_SRCS), $(addsuffix .c, $(UTIL_FILE)))
UTIL_OBJS	= $(addprefix $(DIR_OBJS), $(addsuffix .o, $(UTIL_FILE)))

CHCK_SRCS	= $(addprefix $(DIR_SRCS), $(addsuffix .c, $(CHCK_MAIN)))
CHCK_OBJS	= $(addprefix $(DIR_OBJS), $(addsuffix .o, $(CHCK_MAIN)))
PSSW_SRCS	= $(addprefix $(DIR_SRCS), $(addsuffix .c, $(PSSW_MAIN)))
PSSW_OBJS	= $(addprefix $(DIR_OBJS), $(addsuffix .o, $(PSSW_MAIN)))

.PHONY: all clean fclean re

all: $(NAME)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PUSHSWAP): $(UTIL_OBJS) $(PSSW_OBJS)
		@echo "$(_CYON_)Build the push-swap program...$(_END_)"
		@$(CC) $(CFLAGS) -I $(HEADER) -o $@ $(UTIL_OBJS) $(PSSW_OBJS)
		@echo "$(_GREEN_)******Success Compile******$(_END_)"

$(CHECKER): $(UTIL_OBJS) $(CHCK_OBJS)
		@echo "${_CYON_}Build the checker program...$(_END_)"
		@$(CC) $(CFLAGS) -I $(HEADER) -o $@ $(UTIL_OBJS) $(CHCK_OBJS)
		@echo "$(_GREEN_)******Success Compile******$(_END_)"

clean:
	 @echo "$(_YELLOW_)Clean object files...$(_END_)"
	 @rm -f $(DIR_OBJS)*.o

fclean: clean
	@echo "$(_YELLOW_)Clean executable...$(_END_)"
	@rm -f $(DIR_SRCS)*.gch
	@rm -f $(PUSHSWAP)
	@rm -f $(CHECKER)

re: fclean all
