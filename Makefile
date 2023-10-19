##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rémi BISSON
##
SRC_DIR	=	$(realpath src)/
INC	=	$(realpath include)/
SRC	=	$(SRC_DIR)main.c		\
		$(SRC_DIR)gameloop.c		\
		$(SRC_DIR)display.c		\
		$(SRC_DIR)status_modif.c	\
		$(SRC_DIR)menu.c
OBJ	=	$(SRC:.c=.o)
NAME	=	my_hunter
CFLAGS +=	-Wall -W -Wextra -I$(INC)
CFLAGS +=	-lc_graph_prog -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all clean
