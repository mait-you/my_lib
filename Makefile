# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 11:26:17 by mait-you          #+#    #+#              #
#    Updated: 2025/04/29 09:45:12 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f
NAME        = libft.a

# Directory structure
SRC_DIR     = ./
OBJ_DIR     = obj/

# Directories for categories
_STR_M                  = String_Manipulation/
_STR_T                  = String_Transformations/
_MEM_M                  = Memory_Management/
_CHAR_C                 = Character_Checks/
_OUTPUT_F               = Output_Functions/
_LINKED_L               = Linked_List/
_SAFE_CALLOC            = ft_safe_allocate/
_GNL                    = get_next_line/
_PRINTF                 = ft_printf/

# Source files by category
SAFE_CALLOC             = $(_SAFE_CALLOC)ft_safe_allocate.c \
	$(_SAFE_CALLOC)ft_safe_allocate_action.c $(_SAFE_CALLOC)ft_safe_allocate_utils.c \
	$(_SAFE_CALLOC)memory_fencing.c $(_SAFE_CALLOC)ft_safe_allocate_cleanup.c

STR_MANIPULATION        = $(_STR_M)ft_strlen.c $(_STR_M)ft_strlcpy.c $(_STR_M)ft_strlcat.c \
	$(_STR_M)ft_strchr.c $(_STR_M)ft_strrchr.c $(_STR_M)ft_strncmp.c $(_STR_M)ft_strnstr.c \
	$(_STR_M)ft_strdup.c $(_MEM_M)ft_memcpy.c $(SAFE_CALLOC)

STR_TRANSFORMATIONS     = $(_STR_T)ft_toupper.c $(_STR_T)ft_tolower.c $(_STR_T)ft_strtrim.c \
	$(_STR_T)ft_substr.c $(_STR_T)ft_strjoin.c $(_STR_T)ft_itoa.c $(_STR_T)ft_strmapi.c \
	$(_STR_T)ft_striteri.c $(_STR_T)ft_atoi.c $(_STR_T)ft_split.c $(_MEM_M)ft_memcpy.c \
	$(_STR_M)ft_strlen.c $(_STR_M)ft_strdup.c $(SAFE_CALLOC)

MEM_MANAGEMENT          = $(_MEM_M)ft_memset.c $(_MEM_M)ft_memcpy.c $(_MEM_M)ft_memmove.c \
	$(_MEM_M)ft_bzero.c $(_MEM_M)ft_memchr.c $(_MEM_M)ft_memcmp.c $(_MEM_M)ft_calloc.c

CHAR_CHECKS             = $(_CHAR_C)ft_isalpha.c $(_CHAR_C)ft_isdigit.c \
	$(_CHAR_C)ft_isalnum.c $(_CHAR_C)ft_isascii.c $(_CHAR_C)ft_isprint.c

OUTPUT_FUNCTIONS        = $(_OUTPUT_F)ft_putchar_fd.c $(_OUTPUT_F)ft_putstr_fd.c \
	$(_OUTPUT_F)ft_putendl_fd.c $(_OUTPUT_F)ft_putnbr_fd.c

LINKED_LIST             = $(_LINKED_L)ft_lstnew.c $(_LINKED_L)ft_lstadd_front.c \
	$(_LINKED_L)ft_lstsize.c $(_LINKED_L)ft_lstlast.c $(_LINKED_L)ft_lstadd_back.c \
	$(_LINKED_L)ft_lstdelone.c $(_LINKED_L)ft_lstclear.c $(_LINKED_L)ft_lstiter.c \
	$(_LINKED_L)ft_lstmap.c $(SAFE_CALLOC)

GNL                     = $(_GNL)get_next_line.c $(_GNL)get_next_line_utils.c $(SAFE_CALLOC)

PRINTF                  = $(_PRINTF)ft_printf.c $(_PRINTF)ft_putchr.c $(_PRINTF)ft_putstr.c \
	$(_PRINTF)ft_putadress.c $(_PRINTF)ft_putnbr.c $(_PRINTF)ft_putunbr.c $(_PRINTF)ft_puthexa.c

# All source files
SRCS = $(STR_MANIPULATION) $(STR_TRANSFORMATIONS) $(MEM_MANAGEMENT) $(CHAR_CHECKS) \
    $(OUTPUT_FUNCTIONS) $(LINKED_LIST) $(SAFE_CALLOC) $(GNL) $(PRINTF)

# Generate object file paths
OBJ_STR_MANIPULATION    = $(STR_MANIPULATION:%.c=$(OBJ_DIR)%.o)
OBJ_STR_TRANSFORMATIONS = $(STR_TRANSFORMATIONS:%.c=$(OBJ_DIR)%.o)
OBJ_MEM_MANAGEMENT      = $(MEM_MANAGEMENT:%.c=$(OBJ_DIR)%.o)
OBJ_CHAR_CHECKS         = $(CHAR_CHECKS:%.c=$(OBJ_DIR)%.o)
OBJ_OUTPUT_FUNCTIONS    = $(OUTPUT_FUNCTIONS:%.c=$(OBJ_DIR)%.o)
OBJ_LINKED_LIST         = $(LINKED_LIST:%.c=$(OBJ_DIR)%.o)
OBJ_SAFE_CALLOC         = $(SAFE_CALLOC:%.c=$(OBJ_DIR)%.o)
OBJ_GNL                 = $(GNL:%.c=$(OBJ_DIR)%.o)
OBJ_PRINTF              = $(PRINTF:%.c=$(OBJ_DIR)%.o)
OBJS 					= $(OBJ_STR_MANIPULATION) $(OBJ_STR_TRANSFORMATIONS) \
	$(OBJ_MEM_MANAGEMENT) $(OBJ_CHAR_CHECKS) $(OBJ_OUTPUT_FUNCTIONS) $(OBJ_LINKED_LIST) \
	$(OBJ_SAFE_CALLOC) $(OBJ_GNL) $(OBJ_PRINTF)

# Color definitions
BLACK       = \033[30m
RED         = \033[31m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m
PURPLE      = \033[35m
CYAN        = \033[36m
WHITE       = \033[37m

# Background colors
BLACKB      = \033[40m
REDB        = \033[41m
GREENB      = \033[42m
YELLOWB     = \033[43m
BLUEB       = \033[44m
PURPLEB     = \033[45m
CYANB       = \033[46m
WHITEB      = \033[47m

# Light black
GRAYL       = \033[90m

# Text formatting
B           = \033[1m
BOFF        = \033[22m
I           = \033[3m
IOFF        = \033[23m
U           = \033[4m
UOFF        = \033[24m
R           = \033[7m
ROFF        = \033[27m

# Reset & up
RESET       = \033[0m
UP          = \033[F

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(B)$(GREEN)Library $(YELLOW)$(U)$(NAME)$(RESET) $(GREEN)created successfully!$(RESET)"

# Compile object files
$(OBJ_DIR)%.o: %.c libft.h | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)$(B)Compiling: $(RESET)$(I)$(GRAYL)$<$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

# Clean object files
clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(B)$(RED)Object files cleaned!$(RESET)"

# Clean everything
fclean: clean
	@$(RM) $(NAME)
	@echo "$(B)$(RED)$(UP)Object files & $(YELLOW)$(U)$(NAME)$(RESET) $(RED)removed!$(RESET)"

# Rebuild everything
re: fclean all

# Specific targets for categories
strman:
	@$(MAKE) $(OBJ_STR_MANIPULATION)
	@$(AR) $(NAME) $(OBJ_STR_MANIPULATION)
	@echo "$(GREEN)String manipulation functions added to $(YELLOW)$(U)$(NAME)$(RESET)"
	
strtrn:
	@$(MAKE) $(OBJ_STR_TRANSFORMATIONS)
	@$(AR) $(NAME) $(OBJ_STR_TRANSFORMATIONS)
	@echo "$(GREEN)String Transformations functions added to $(YELLOW)$(U)$(NAME)$(RESET)"

memory:
	@$(MAKE) $(OBJ_MEM_MANAGEMENT)
	@$(AR) $(NAME) $(OBJ_MEM_MANAGEMENT)
	@echo "$(GREEN)Memory management functions added to $(YELLOW)$(U)$(NAME)$(RESET)"

char:
	@$(MAKE) $(OBJ_CHAR_CHECKS)
	@$(AR) $(NAME) $(OBJ_CHAR_CHECKS)
	@echo "$(GREEN)Character check functions added to $(YELLOW)$(U)$(NAME)$(RESET)"

output:
	@$(MAKE) $(OBJ_OUTPUT_FUNCTIONS)
	@$(AR) $(NAME) $(OBJ_OUTPUT_FUNCTIONS)
	@echo "$(GREEN)Output functions added to $(YELLOW)$(U)$(NAME)$(RESET)"

node:
	@$(MAKE) $(OBJ_LINKED_LIST)
	@$(AR) $(NAME) $(OBJ_LINKED_LIST)
	@echo "$(GREEN)Linked list functions added to $(YELLOW)$(U)$(NAME)$(RESET)"

safecalloc:
	@$(MAKE) $(OBJ_SAFE_CALLOC)
	@$(AR) $(NAME) $(OBJ_SAFE_CALLOC)
	@echo "$(GREEN)Safe calloc functions added to $(YELLOW)$(U)$(NAME)$(RESET)"

gnl:
	@$(MAKE) $(OBJ_GNL)
	@$(AR) $(NAME) $(OBJ_GNL)
	@echo "$(GREEN)Get Next Line functions added to $(YELLOW)$(U)$(NAME)$(RESET)"

printf:
	@$(MAKE) $(OBJ_PRINTF)
	@$(AR) $(NAME) $(OBJ_PRINTF)
	@echo "$(GREEN)Printf functions added to $(YELLOW)$(U)$(NAME)$(RESET)"

# Phony targets
.PHONY: all clean fclean re strman strtrn memory char output node safecalloc gnl printf