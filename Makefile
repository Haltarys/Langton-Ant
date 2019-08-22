SRC	=	src/main.c	\
		src/langton.c	\
		src/print.c	\
		src/move.c	\
		src/pause.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	langton

CFLAGS  +=	-Wall -pedantic -I include

LFLAGS	= -lncurses

all: $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
