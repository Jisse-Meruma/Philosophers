### VAR #######################################################
NAME		:=	philo

DEBUGGING	?=

HEADER		:=	-I includes
HEADERS		:=	includes/philo.h
OBJ_DIR		:=	./obj
SRC_DIR 	:=	./src

### UTILS #####################################################
CFLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -rf

SRC 	:=	main.c			\
			parse.c			\
			philo.c			\
			time.c			\
			monitoring.c	\
			error.c			\
			mutex_destroy.c \
			mutex_init.c    \
			tasks.c			

OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

## BON_SRC :=

## BON_OBJ :=  $(BON_SRC:_bonus.c=_bonus.o)

## Regular Colors ##############################################
Color_Off	=	"\033[0m"			# Text Reset
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White

### EXEC #######################################################

ifdef DEBUG
	DEBUGGING += -fsanitize=thread -g
endif

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(Yellow) Building.. 🏠$(Color_Off)
	@echo -----------------------
	@$(CC) $^ $(DEBUGGING) -o $(NAME) 
	@echo $(Green) Complete ✅ $(Color_Off)
	@echo -----------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo $(Purple) Compiling.. 🧱 $< $(Color_Off)
	@echo -----------------------
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ 

$(OBJ_DIR):
	@mkdir $@

clean:
	@echo $(Cyan) Sweeping.. 💥 $(Color_Off)
	@echo -----------------------
	@$(RM) $(OBJ) $(BON_OBJ)

fclean:
	@echo $(Red) Thorough sweeping.. 💥 $(Color_Off)
	@echo -----------------------
	@$(RM) $(NAME) $(OBJ) $(BON_OBJ)

re: fclean all

.PHONY: clean all fclean re