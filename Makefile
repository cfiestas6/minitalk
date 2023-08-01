SOURCES = server.c client.c utils.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: server client

server: server.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

client: client.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) *.o

fclean: clean
	$(RM) server client

re: fclean all

.PHONY: all clean fclean re
