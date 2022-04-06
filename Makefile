##
## EPITECH PROJECT, 2021
## My_Defender
## File description:
## Makefile
##

MAIN		=	src/json/localmain.c			\

SRC			=	src/json/generate/file_gestion.c			\
				src/json/generate/str_preprocessing.c		\
				src/json/generate/object_preprocessing.c	\
				src/json/generate/extract_fields.c			\
				src/json/generate/json_split.c				\
				src/json/generate/json_error_handling.c		\
				src/json/use/free_json.c					\
				src/json/use/json_get_by_name.c				\
				src/json/use/json_get_by_index.c			\

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
