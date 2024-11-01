<<<<<<< HEAD
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c $(SRCS_2)
SRCS_2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c
OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -f
NAME = libft.a

RED = \033[31m
GREEN = \033[32m
RESET = \033[0m

all: $(NAME) clean main

# ar rcs libft.a ft_isalpha.o 
$(NAME):$(OBJS)
#	@echo "$(GREEN)Creat libft.a$(RESET)"
	@$(AR) $(NAME) $(OBJS)

# gcc -Wall -Wextra -Werror -c ft_isalpha.c -o ft_isalpha.o 
%.o: %.c
#	@echo "$(GREEN)Creat object file$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
#	@echo "$(RED)Clean object file$(RESET)"
	@$(RM) -f $(OBJS)


fclean:
#	@echo "$(RED)Clean libft.a$(RESET)"
	@$(RM) $(NAME)

re: fclean clean

main:
#	@echo "$(GREEN)Creat main.c$(RESET)"
	@$(CC) $(CFLAGS) -L. -lft 2_main.c
=======
CC					= gcc
C_FLAGS				= -Wall -Wextra -Werror
LIBC_FILES			= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c $(ADDITIONAL_FILES)

ADDITIONAL_FILES	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c

BONUS_FILES			= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c

LIBC_OBJS	= $(LIBC_FILES:.c=.o)
BONUS_OBJS	= $(BONUS_FILES:.c=.o)
AR			= ar rcs
RM			= rm -f
NAME		= libft.a

RED			= \033[1;31m
BLUE		= \033[1;34m
RESIT		= \033[0m
UP			= \033[F

all: libc

libc: $(LIBC_OBJS)
	@echo "$(BLUE)Make libf wiht LIBC_FILES & ADDITIONAL_FILES$(RESIT)"
	@$(AR) $(NAME) $(LIBC_OBJS)

bonus: $(LIBC_OBJS) $(BONUS_OBJS)
	@echo "$(BLUE)Make libf wiht LIBC_FILES & ADDITIONAL_FILES & BONUS_FILES$(RESIT)"
	@$(AR) $(NAME) $(BONUS_OBJS) $(LIBC_OBJS)

%.o: %.c
	@echo "$(BLUE)Make Objects Files$(RESIT)"
	@$(CC) $(C_FLAGS) -c $< -o $@

clean:
	@echo "$(RED)Clean Objects Files$(RESIT)"
	@$(RM) $(LIBC_OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "$(RED)$(UP)Clean Objects Files & Libft$(RESET)"
	@$(RM) $(NAME)

re: fclean all

main:
	@clear
	@echo "$(BLUE)Meake a.out File$(RESIT)"
	@$(CC) $(C_FLAGS) -L. -lft 2_main.c

>>>>>>> Day 11
