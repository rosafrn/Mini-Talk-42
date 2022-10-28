NAME	=
CLIENT	=	client
SERVER	=	server


SRC_CLIENT	=	client.c
SRC_SERVER	=	server.c

INCS		=	. 
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror -fsanitize=address
RM			=	rm -f


all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	$(CC) $(CFLAG) $(SRC_SERVER) -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAG) $(SRC_CLIENT) -o $(CLIENT)

clean:
	$(RM) $(CLIENT) $(SERVER)

fclean:
	$(RM) $(CLIENT) $(SERVER)

re: fclean all 
