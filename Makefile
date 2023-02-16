CC			= g++-11 -Wall -Wextra -Werror -std=c++98 -pedantic
RM			= rm -rf
MKDIR		= mkdir -p
NAME		= ./ft_container
NAME_SHORT	= ft_container

INCS_DIR	= inc inc/utils
MAIN_INC	= -I$(INCS_DIR)

SRCS_DIR 	= ./src/
SRC_NAMES	= 	main.cpp


SRCS		= $(addprefix $(SRCS_DIR), $(SRC_NAMES))

BUILDDIR	= build build/utils
OBJS		=  $(addprefix $(BUILDDIR), $(SRC_NAMES:.cpp=.o))

_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]


all			: $(NAME)

$(BUILDDIR):
			@mkdir -p $(BUILDDIR)

$(BUILDDIR)%.o			: $(SRCS_DIR)%.cpp
			@echo "[..] $(NAME_SHORT)... compiling $*.cpp\r\c"
			@$(CC) $(MAIN_INC) -c $< -o $@
			@echo "$(_CLEAR)"

$(NAME)		: $(BUILDDIR) $(OBJS)
			@$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) compiled"

clean		:
			@$(RM) $(BUILDDIR)

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
