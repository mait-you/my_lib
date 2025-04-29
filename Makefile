# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 09:51:24 by mait-you          #+#    #+#              #
#    Updated: 2025/04/29 10:25:33 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
NAME        = libft.a

# Directories for categories
_STR_M                  = String_Manipulation/
_STR_T                  = String_Transformations/
_MEM_M                  = Memory_Management/
_CHAR_C                 = Character_Checks/
_OUTPUT_F               = Output_Functions/
_LINKED_L               = Linked_List/
_SAFE_ALLOC            	= ft_safe_allocate/
_GNL                    = get_next_line/
_PRINTF                 = ft_printf/
_HEADERS				= include/
_OBJS_DIR				= obj/

# Source files by category
HEADERS					= $(_HEADERS)libft.h $(_HEADERS)ft_printf.h \
	$(_HEADERS)get_next_line.h $(_HEADERS)ft_safe_allocate.h

SAFE_ALLOC             = $(_SAFE_ALLOC)ft_safe_allocate.c \
	$(_SAFE_ALLOC)ft_safe_allocate_action.c $(_SAFE_ALLOC)ft_safe_allocate_utils.c \
	$(_SAFE_ALLOC)memory_fencing.c $(_SAFE_ALLOC)ft_safe_allocate_cleanup.c

STR_MANIPULATION        = $(_STR_M)ft_strlen.c $(_STR_M)ft_strlcpy.c $(_STR_M)ft_strlcat.c \
	$(_STR_M)ft_strchr.c $(_STR_M)ft_strrchr.c $(_STR_M)ft_strncmp.c $(_STR_M)ft_strnstr.c \
	$(_STR_M)ft_strdup.c $(_MEM_M)ft_memcpy.c $(SAFE_ALLOC)

STR_TRANSFORMATIONS     = $(_STR_T)ft_toupper.c $(_STR_T)ft_tolower.c $(_STR_T)ft_strtrim.c \
	$(_STR_T)ft_substr.c $(_STR_T)ft_strjoin.c $(_STR_T)ft_itoa.c $(_STR_T)ft_strmapi.c \
	$(_STR_T)ft_striteri.c $(_STR_T)ft_atoi.c $(_STR_T)ft_split.c $(_MEM_M)ft_memcpy.c \
	$(_STR_M)ft_strlen.c $(_STR_M)ft_strdup.c $(SAFE_ALLOC)

MEM_MANAGEMENT          = $(_MEM_M)ft_memset.c $(_MEM_M)ft_memcpy.c $(_MEM_M)ft_memmove.c \
	$(_MEM_M)ft_bzero.c $(_MEM_M)ft_memchr.c $(_MEM_M)ft_memcmp.c $(_MEM_M)ft_calloc.c

CHAR_CHECKS             = $(_CHAR_C)ft_isalpha.c $(_CHAR_C)ft_isdigit.c \
	$(_CHAR_C)ft_isalnum.c $(_CHAR_C)ft_isascii.c $(_CHAR_C)ft_isprint.c

OUTPUT_FUNCTIONS        = $(_OUTPUT_F)ft_putchar_fd.c $(_OUTPUT_F)ft_putstr_fd.c \
	$(_OUTPUT_F)ft_putendl_fd.c $(_OUTPUT_F)ft_putnbr_fd.c

LINKED_LIST             = $(_LINKED_L)ft_lstnew.c $(_LINKED_L)ft_lstadd_front.c \
	$(_LINKED_L)ft_lstsize.c $(_LINKED_L)ft_lstlast.c $(_LINKED_L)ft_lstadd_back.c \
	$(_LINKED_L)ft_lstdelone.c $(_LINKED_L)ft_lstclear.c $(_LINKED_L)ft_lstiter.c \
	$(_LINKED_L)ft_lstmap.c $(SAFE_ALLOC)

GNL                     = $(_GNL)get_next_line.c $(_GNL)get_next_line_utils.c $(SAFE_ALLOC)

PRINTF                  = $(_PRINTF)ft_printf.c $(_PRINTF)ft_putchr.c $(_PRINTF)ft_putstr.c \
	$(_PRINTF)ft_putadress.c $(_PRINTF)ft_putnbr.c $(_PRINTF)ft_putunbr.c $(_PRINTF)ft_puthexa.c

# Colors for terminal output
RESET				:= \033[0m
GREEN				:= \033[1;32m
YELLOW				:= \033[4;33m
BLUE				:= \033[1;34m
RED					:= \033[1;31m
GRAYL				:= \033[3;90m
PURPLE				:= \033[1;35m
BOLD				:= \033[1m

# All source files
SRCS = $(STR_MANIPULATION) $(STR_TRANSFORMATIONS) $(MEM_MANAGEMENT) $(CHAR_CHECKS) \
    $(OUTPUT_FUNCTIONS) $(LINKED_LIST) $(SAFE_ALLOC) $(GNL) $(PRINTF)

# Object files
OBJS = $(SRCS:%.c=$(_OBJS_DIR)%.o)

# Object files for each category
STR_M_OBJS = $(STR_MANIPULATION:%.c=$(_OBJS_DIR)%.o)
STR_T_OBJS = $(STR_TRANSFORMATIONS:%.c=$(_OBJS_DIR)%.o)
MEM_M_OBJS = $(MEM_MANAGEMENT:%.c=$(_OBJS_DIR)%.o)
CHAR_C_OBJS = $(CHAR_CHECKS:%.c=$(_OBJS_DIR)%.o)
OUT_F_OBJS = $(OUTPUT_FUNCTIONS:%.c=$(_OBJS_DIR)%.o)
LL_OBJS = $(LINKED_LIST:%.c=$(_OBJS_DIR)%.o)
SAFE_C_OBJS = $(SAFE_ALLOC:%.c=$(_OBJS_DIR)%.o)
GNL_OBJS = $(GNL:%.c=$(_OBJS_DIR)%.o)
PRINTF_OBJS = $(PRINTF:%.c=$(_OBJS_DIR)%.o)

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)Library $(YELLOW)$(NAME)$(RESET) $(GREEN)created successfully!$(RESET)"

# Compile object files
$(_OBJS_DIR)%.o: %.c $(HEADERS) | $(_OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $(RESET)$(GRAYL)$<$(RESET)"

$(_OBJS_DIR):
	@mkdir -p $@

# Category-specific targets
str_manipulation: $(STR_M_OBJS) | $(_OBJS_DIR)
	@$(AR) $(NAME) $(STR_M_OBJS)
	@echo "$(GREEN)Category $(YELLOW)String Manipulation$(RESET) $(GREEN)compiled successfully!$(RESET)"

str_transformations: $(STR_T_OBJS) | $(_OBJS_DIR)
	@$(AR) $(NAME) $(STR_T_OBJS)
	@echo "$(GREEN)Category $(YELLOW)String Transformations$(RESET) $(GREEN)compiled successfully!$(RESET)"

mem_management: $(MEM_M_OBJS) | $(_OBJS_DIR)
	@$(AR) $(NAME) $(MEM_M_OBJS)
	@echo "$(GREEN)Category $(YELLOW)Memory Management$(RESET) $(GREEN)compiled successfully!$(RESET)"

char_checks: $(CHAR_C_OBJS) | $(_OBJS_DIR)
	@$(AR) $(NAME) $(CHAR_C_OBJS)
	@echo "$(GREEN)Category $(YELLOW)Character Checks$(RESET) $(GREEN)compiled successfully!$(RESET)"

output_functions: $(OUT_F_OBJS) | $(_OBJS_DIR)
	@$(AR) $(NAME) $(OUT_F_OBJS)
	@echo "$(GREEN)Category $(YELLOW)Output Functions$(RESET) $(GREEN)compiled successfully!$(RESET)"

linked_list: $(LL_OBJS) | $(_OBJS_DIR)
	@$(AR) $(NAME) $(LL_OBJS)
	@echo "$(GREEN)Category $(YELLOW)Linked List$(RESET) $(GREEN)compiled successfully!$(RESET)"

safe_alloc: $(SAFE_C_OBJS) | $(_OBJS_DIR)
	@$(AR) $(NAME) $(SAFE_C_OBJS)
	@echo "$(GREEN)Category $(YELLOW)Safe Calloc$(RESET) $(GREEN)compiled successfully!$(RESET)"

gnl: $(GNL_OBJS) | $(_OBJS_DIR)
	@$(AR) gnl.a $(GNL_OBJS)
	@echo "$(GREEN)Category $(YELLOW)Get Next Line$(RESET) $(GREEN)compiled successfully!$(RESET)"

printf: $(PRINTF_OBJS) | $(_OBJS_DIR)
	@$(AR) printf.a $(PRINTF_OBJS)
	@echo "$(GREEN)Category $(YELLOW)Printf$(RESET) $(GREEN)compiled successfully!$(RESET)"

# List all categories target
categories:
	@echo "$(BLUE)Available categories:$(RESET)"
	@echo "$(YELLOW)- str_manipulation$(RESET)    : String manipulation functions"
	@echo "$(YELLOW)- str_transformations$(RESET) : String transformation functions"
	@echo "$(YELLOW)- mem_management$(RESET)      : Memory management functions"
	@echo "$(YELLOW)- char_checks$(RESET)         : Character check functions"
	@echo "$(YELLOW)- output_functions$(RESET)    : Output functions"
	@echo "$(YELLOW)- linked_list$(RESET)         : Linked list functions"
	@echo "$(YELLOW)- safe_alloc$(RESET)          : Safe memory allocation functions"
	@echo "$(YELLOW)- gnl$(RESET)                 : Get Next Line functions"
	@echo "$(YELLOW)- printf$(RESET)              : Printf functions"

# Clean object files
clean:
	@rm -rf $(_OBJS_DIR)
	@echo "$(RED)Cleaned object files.$(RESET)"

# Clean everything
fclean: clean
	@rm -f $(NAME) str_manipulation.a str_transformations.a mem_management.a char_checks.a \
	output_functions.a linked_list.a safe_alloc.a gnl.a printf.a
	@echo "$(RED)Cleaned all libraries.$(RESET)"

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re str_manipulation str_transformations mem_management char_checks \
output_functions linked_list safe_alloc gnl printf categories