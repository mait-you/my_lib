# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 11:26:17 by mait-you          #+#    #+#              #
#    Updated: 2024/11/08 13:50:05 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_STR_M					= String_Manipulation/
STR_MANIPULATION		= $(_STR_M)ft_strlen.c $(_STR_M)ft_strlcpy.c $(_STR_M)ft_strlcat.c $(_STR_M)ft_strchr.c \
	$(_STR_M)ft_strrchr.c $(_STR_M)ft_strncmp.c $(_STR_M)ft_strnstr.c $(_STR_M)ft_strdup.c
STR_MANIPULATION_OBJ	= $(STR_MANIPULATION:.c=.o)

_STR_T					= String_Transformations/
STR_TRANSFORMATIONS		= $(_STR_T)ft_toupper.c $(_STR_T)ft_tolower.c $(_STR_T)ft_strtrim.c $(_STR_T)ft_substr.c \
	$(_STR_T)ft_strjoin.c $(_STR_T)ft_itoa.c $(_STR_T)ft_strmapi.c $(_STR_T)ft_striteri.c $(_STR_T)ft_atoi.c \
	$(_STR_T)ft_split.c
STR_TRANSFORMATIONS_OBJ	= $(STR_TRANSFORMATIONS:.c=.o)

_MEN_M					= Memory_Management/
MEM_MANAGEMENT			= $(_MEN_M)ft_memset.c $(_MEN_M)ft_memcpy.c $(_MEN_M)ft_memmove.c $(_MEN_M)ft_bzero.c \
	$(_MEN_M)ft_memchr.c $(_MEN_M)ft_memcmp.c $(_MEN_M)ft_calloc.c
MEM_MANAGEMENT_OBJ		= $(MEM_MANAGEMENT:.c=.o)

_CHAR_C					= Character_Checks/
CHAR_CHECKS				= $(_CHAR_C)ft_isalpha.c $(_CHAR_C)ft_isdigit.c $(_CHAR_C)ft_isalnum.c $(_CHAR_C)ft_isascii.c \
	$(_CHAR_C)ft_isprint.c
CHAR_CHECKS_OBJ			= $(CHAR_CHECKS:.c=.o)

_OUTPUT_F				= Output_Functions/
OUTPUT_FUNCTIONS		= $(_OUTPUT_F)ft_putchar_fd.c $(_OUTPUT_F)ft_putstr_fd.c $(_OUTPUT_F)ft_putendl_fd.c \
	$(_OUTPUT_F)ft_putnbr_fd.c
OUTPUT_FUNCTIONS_OBJ	= $(OUTPUT_FUNCTIONS:.c=.o)

_LINKED_L				= Linked_List_Bonus/
LINKED_LIST				= $(_LINKED_L)ft_lstnew_bonus.c $(_LINKED_L)ft_lstadd_front_bonus.c $(_LINKED_L)ft_lstsize_bonus.c \
	$(_LINKED_L)ft_lstlast_bonus.c $(_LINKED_L)ft_lstadd_back_bonus.c $(_LINKED_L)ft_lstdelone_bonus.c $(_LINKED_L)ft_lstclear_bonus.c \
	$(_LINKED_L)ft_lstiter_bonus.c $(_LINKED_L)ft_lstmap_bonus.c
LINKED_LIST_OBJ			= $(LINKED_LIST:.c=.o)

ALL_FUNCTIONS_OBJ		= $(STR_MANIPULATION_OBJ) $(STR_TRANSFORMATIONS_OBJ) $(MEM_MANAGEMENT_OBJ) $(CHAR_CHECKS_OBJ) \
	$(OUTPUT_FUNCTIONS_OBJ) $(LINKED_LIST_OBJ)

CC			= cc
C_FLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f
NAME		= libft.a

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
PURPLE		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m

# background color
BLACKB		= \033[40m
REDB		= \033[41m
GREENB		= \033[42m
YELLOWB		= \033[43m
BLUEB		= \033[44m
PURPLEB		= \033[45m
CYANB		= \033[46m
WHITEB		= \033[47m

# Light Black
GRAYL		= \033[90m


# bold
B			= \033[1m
BOFF		= \033[22m

# italics
I			= \033[3m
IOFF		= \033[23m

# underline
U			= \033[4m
UOFF		= \033[24m

# invert
R			= \033[7m
ROFF		= \033[27m

# reset
RESET		= \033[0m

# up
UP			= \033[F

all: $(NAME)

$(NAME): $(ALL_FUNCTIONS_OBJ)
	@$(AR) $(NAME) $(ALL_FUNCTIONS_OBJ)
	@echo "$(B)$(GREEN)Make $(YELLOW)$(U)$(NAME)$(RESET) $(GREEN)with ALL_FUNCTIONS$(RESET)"

strManipulation: $(STR_MANIPULATION_OBJ)
	@$(AR) $(NAME) $(STR_MANIPULATION_OBJ)
	@echo "$(GREEN)Make $(YELLOW)$(U)$(NAME)$(RESET) $(RESET)$(GREEN)with STR_MANIPULATION$(RESET)"

strTransformations: $(STR_TRANSFORMATIONS_OBJ)
	@$(AR) $(NAME) $(STR_TRANSFORMATIONS_OBJ)
	@echo "$(GREEN)Make $(YELLOW)$(U)$(NAME)$(RESET) $(GREEN)with STR_TRANSFORMATIONS$(RESET)"

memManagement: $(MEM_MANAGEMENT_OBJ)
	@$(AR) $(NAME) $(MEM_MANAGEMENT_OBJ)
	@echo "$(GREEN)Make $(YELLOW)$(U)$(NAME)$(RESET) $(GREEN)with MEM_MANAGEMENT$(RESET)"

charChecks: $(CHAR_CHECKS_OBJ)
	@$(AR) $(NAME) $(CHAR_CHECKS_OBJ)
	@echo "$(GREEN)Make $(YELLOW)$(U)$(NAME)$(RESET) $(GREEN)with CHAR_CHECKS$(RESET)"

outputFunctions: $(OUTPUT_FUNCTIONS_OBJ)
	@$(AR) $(NAME) $(OUTPUT_FUNCTIONS_OBJ)
	@echo "$(GREEN)Make $(YELLOW)$(U)$(NAME)$(RESET) $(GREEN)with OUTPUT_FUNCTIONS$(RESET)"

linkedList: $(LINKED_LIST_OBJ)
	@$(AR) $(NAME) $(LINKED_LIST_OBJ)
	@echo "$(GREEN)Make $(YELLOW)$(U)$(NAME)$(RESET) $(GREEN)with LINKED_LIST$(RESET)"

%.o: %.c libft.h
	@$(CC) $(C_FLAGS) -c $< -o $@
	@echo "$(BLUE)$(B)Make: $(RESET)$(I)$(GRAYL)$@$(RESET)"


clean:
	@$(RM) $(STR_MANIPULATION_OBJ) $(STR_TRANSFORMATIONS_OBJ) $(MEM_MANAGEMENT_OBJ) $(CHAR_CHECKS_OBJ) \
	$(OUTPUT_FUNCTIONS_OBJ) $(LINKED_LIST_OBJ)
	@clear
	@echo "$(B)$(RED)Clean Object Files$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(B)$(RED)$(UP)Clean Object Files & $(YELLOW)$(U)$(NAME)$(RESET)"

re: fclean all

.PHONY: clean
