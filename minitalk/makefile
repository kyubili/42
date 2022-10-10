# COLORS
BLUE	= \033[1;36m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
RESET	= \033[0m

CC		=	cc
FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

FILES	=	server.c \
			client.c

PRINFT	= ./ft_printf/libftprintf.a

UTILS	= 	$(addprefix $(FOLDER), utils.c)

SRV		=	server
SRVF	=	$(addprefix $(FOLDER), server.c)

CLI		=	client
CLIF	=	$(addprefix $(FOLDER), client.c)

SRC 	=	$(addprefix $(FOLDER), $(FILES))
OBJ 	=	$(SRC:.c=.o)

all: $(SERVER) $(CLIENT)
	@$(MAKE) -C ./ft_printf
	@$(CC) $(FLAGS) $(PRINFT) $(SRVF) -o $(SRV)
	@$(CC) $(FLAGS) $(PRINFT) $(CLIF) -o $(CLI)
	@echo "[$(BLUE)created$(RESET)]: libftprintf.a, server & slient"

clean:
	@$(MAKE) -C ./ft_printf clean
	@$(RM) $(OBJ)
	@echo "[$(RED)deleted$(RESET)]: *.o files"

fclean: clean
	@$(MAKE) -C ./ft_printf fclean
	@$(RM) server
	@$(RM) client
	@echo "[$(RED)deleted$(RESET)]: libftprintf.a, server & slient"

re: fclean all

.PHONY: all clean fclean re