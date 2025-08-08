NAME = program
CC = cc
SRC = main.c design.c
RM = rm
all:
	$(CC) $(SRC) -o $(NAME)
clean:
	$(RM) -rf $(NAME)
re: clean all