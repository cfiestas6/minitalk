# Minitalk

## Overview
Minitalk is a communication program implemented in C, utilizing UNIX signals to enable message exchange between a client and a server. This project is part of the 42 School curriculum, showcasing skills in system programming and inter-process communication.

## Components
- **Server (`server.c`)**: The server program runs continuously, waiting for messages from clients. It prints the received message to the standard output. The server's PID is displayed upon startup.
- **Client (`client.c`)**: The client program sends a string to the server. It requires the server's PID and the string to be sent as command-line arguments.
- **Utilities (`utils.c`)**: This file contains utility functions like `ft_strlen`, `ft_atoi`, and `ft_putnbr` used by both the client and server.
- **Header File (`minitalk.h`)**: The header file includes necessary library imports and declarations of utility functions.

## Compilation
The project can be compiled using the provided `Makefile`:
- To compile both the server and client: `make all`
- To clean up object files: `make clean`
- To remove objects and binary files: `make fclean`
- To recompile: `make re`

## Usage
1. Start the server to get its PID:
   ```
   ./server
   ```
2. Use the client to send a message to the server using its PID:
   ```
   ./client [Server_PID] [Message]
   ```

## Implementation Details
- The server uses signal handlers to assemble characters from bits sent by the client.
- The client sends characters as a series of bits using UNIX signals (`SIGUSR1` for 0, `SIGUSR2` for 1).
- Both programs handle errors and edge cases, ensuring robust communication.
