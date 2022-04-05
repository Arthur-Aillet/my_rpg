##
## EPITECH PROJECT, 2021
## My_Defender
## File description:
## Makefile
##

MAIN		=	src/json/localmain.c			\

SRC			=	src/json/file_gestion.c			\
				src/json/str_preprocessing.c	\
				src/json/object_preprocessing.c	\
				src/json/extract_fields.c		\
				src/json/json_split.c			\
				src/json/free_json.c			\
				src/json/json_error_handling.c	\

MAINOBJ		=	$(MAIN:.c=.o)
OBJ			=	$(SRC:.c=.o)

NAME		=	json_tests

LIB			= 	-L. ./lib/libmy.a	\


CPPFLAGS	+=	-I include/
CFLAGS		+=	-Wall -Wextra -g3

$(NAME):		$(MAINOBJ) $(OBJ)
				make -C lib/my/
				gcc -o $(NAME) $(MAINOBJ) $(OBJ) $(CFLAGS) $(LIB)

all:			$(NAME)

c:				$(NAME)
				./$(NAME)
				mr_clean

clean:
				rm -f $(OBJ) $(MAINOBJ)
				rm -f criterion_test

fclean: 		clean
				rm -f $(NAME)

re: 			fclean all

tests_run:
				make -C lib/
				gcc -o criterion_test tests/tests.c $(TESTS) --coverage \
				-lcriterion -L. ./lib/lib.a
				./criterion_test

.PHONY	=		all clean fclean re tests_run
