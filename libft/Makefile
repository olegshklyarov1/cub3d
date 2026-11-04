# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olshklya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 16:42:28 by olshklya          #+#    #+#              #
#    Updated: 2025/10/21 18:51:32 by olshklya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c\
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c\
ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c\
ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c\
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_atoi.c\
ft_strnstr.c ft_memcmp.c ft_strdup.c ft_calloc.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
ft_putendl_fd.c ft_striteri.c ft_putnbr_fd.c

NAME = libft.a

OBJ = $(SRC:.c=.o)

RM = rm -rf

all : $(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)
clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY:all clean fclean re so
