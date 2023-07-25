SOURCES = server.c client.c utils.c
OBJECTS = $(SOUCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: server client

ft_printf: 
	make -sC ./ft_printf

server: server.o ft_printf minitalk.h
	$(CC) -o $@ $< -L./ft_printf -lftprintf

client: client.o ft_printf minitalk.h
	$(CC) -o $@ $< -L./ft_printf -lftprintf
%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean: 
	$(RM) *.o ./ft_printf/*.o

fclean: clean
	$(RM) server client ft_printf/libftprintf.a

re: fclean all

.PHONY: all ft_printf clean fclean re
