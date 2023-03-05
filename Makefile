CC = gcc
SRC = check_op.c main.c opcodes.c opcodes2.c opcodes3.c opcodes4.c
OBJ = $(SRC:%.c=%.o)
NAME = monty
CFLAGS = -Wall -Wextra -Werror -pedantic
RM = rm -f

.PHONY: all clean oclean fclean re

all: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: oclean all
