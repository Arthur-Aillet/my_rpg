##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## MAKEFILE
##

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME			=			binaire

NAME_TEST		=			unit_test

## ==========================[PATHS]==========================

SRC_PATH		=			src/

UTILS_PATH		=			$(SRC_PATH)utils/

WIN_PATH		=			$(SRC_PATH)window/

TEST_PATH		=			tests/

## ===========================[SRC]===========================

SRC_UTILS		=			$(UTILS_PATH)my_error_handling.c		\
							$(UTILS_PATH)my_help.c					\

SRC_WINDOW		=			$(WIN_PATH)my_window.c					\

SRC_GLOBAL		=			$(SRC_UTILS)							\
							$(SRC_WINDOW)							\

SRC				=			$(SRC_GLOBAL)							\
							main.c

TEST_SRC		=			$(TEST_PATH)tests_error_handling.c		\

OBJ				=			$(SRC:.c=.o)

## =========================[OPTIONS]=========================

CFLAGS			=			-Wall -Wextra

CPPFLAGS		=			-I include

LDFLAGS			=			-L lib -lmy							\
							-lcsfml-graphics -lcsfml-system 	\
							-lcsfml-audio -lcsfml-window		\
							-lm									\

CRIT			=			$(LDFLAGS) $(CPPFLAGS) -lcriterion --coverage

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

all:
		make re -C lib/my
		make $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

re:			fclean	all

clean:
		make clean -C lib/my
		rm -rf $(OBJ)

fclean:		clean
		make fclean -C lib/my
		rm -rf $(NAME)
		rm -rf $(NAME_TEST)
		rm -rf *gcda
		rm -rf *gcno

tests_run:
	make re -C lib/my
	gcc -o $(NAME_TEST) $(SRC_GLOBAL) $(SRC_TEST) $(TEST_SRC) $(CRIT)
	./$(NAME_TEST)

## ===========================[END]===========================

.PHONY:	all	re	clean	fclean	tests_run
