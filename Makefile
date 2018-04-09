# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 11:58:15 by maduhoux          #+#    #+#              #
#    Updated: 2018/04/06 16:45:11 by maduhoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
OBJDIR	=	obj/
SRCDIR	=	srcs/
FILES	=	misc.c \
			ft_printf.c \
			ft_tab.c \
			parser.c \
			check.c \
			declare.c \
			flag_finder.c \
			ft_conversion.c \
			printer/string.c \
			printer/hexa.c \
			printer/octal.c \
			printer/signed.c \
			printer/unsigned.c \
			printer/wchar.c \
			printer/wchar_octets.c \
			printer/nothing.c \
			convert.c \
			bin.c
INCLUDE	=	includes/
SRC		=	$(FILES:%.c=$(SRCDIR)%.c)
OBJ		=	$(subst printer/,, $(FILES:%.c=$(OBJDIR)%.o))

VPATH	= 	$(shell find $(SRCDIR) -type d)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	cd $(OBJDIR) && ar -x ../libft/libft.a && ar -rc ../$(NAME) *.o
	ranlib $(NAME)

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	@gcc -o $@ -c $< $(CFLAGS) -I $(INCLUDE)

clean:
	make clean -C libft/
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
