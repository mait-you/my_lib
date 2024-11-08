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

CC					= cc
CFLAGS				= -Wall -Wextra -Werror
LIBC_FILES			= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS_FILES			= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

LIBC_OBJS	= $(LIBC_FILES:.c=.o)
BONUS_OBJS	= $(BONUS_FILES:.c=.o)
AR			= ar rcs
RM			= rm -f
NAME		= libft.a

RED			= \033[1;31m
BLUE		= \033[1;34m
RESIT		= \033[0m
UP			= \033[F

all: $(NAME)

$(NAME): $(LIBC_OBJS)
	@echo "$(BLUE)Make libf wiht LIBC_FILES & ADDITIONAL_FILES$(RESIT)"
	@$(AR) $(NAME) $(LIBC_OBJS)

bonus: $(LIBC_OBJS) $(BONUS_OBJS)
	@echo "$(BLUE)Make libf wiht LIBC_FILES & ADDITIONAL_FILES & BONUS_FILES$(RESIT)"
	@$(AR) $(NAME) $(BONUS_OBJS) $(LIBC_OBJS)

%.o: %.c libft.h
	@echo "$(BLUE)Make Objects Files$(RESIT)"
	@$(CC) $(C_FLAGS) -c $< -o $@

clean:
	@echo "$(RED)Clean Objects Files$(RESIT)"
	@$(RM) $(LIBC_OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "$(RED)$(UP)Clean Objects Files & Libft$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean