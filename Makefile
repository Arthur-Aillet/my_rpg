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
				src/json/use/get/json_get_by_name.c			\
				src/json/use/get/json_get_by_index.c		\
				src/json/use/get/json_display_obj.c			\
				src/json/use/json_main.c					\
															\
				src/json/use/edit/json_add_field.c			\
				src/json/use/edit/json_edit_by_name.c		\
				src/json/use/edit/manage_json.c				\
				src/json/generate/duplicate_data.c			\
				src/json/generate/allocation.c				\

MAINOBJ		=	$(MAIN:.c=.o)
OBJ			=	$(SRC:.c=.o)

NAME		=	json_tests

LIB			= 	-L. ./lib/libmy.a	\


CPPFLAGS	+=	-I include/
CFLAGS		+=	-Wall -Wextra -g3 -ggdb

$(NAME):		$(MAINOBJ) $(OBJ)
				make -C lib/my/
				gcc -o $(NAME) $(MAINOBJ) $(OBJ) $(CFLAGS) $(LIB)

all:			$(NAME)

MENU_PATH		=			$(SRC_PATH)menu/

GAME_PATH		=			$(SRC_PATH)game/

MINGAME_PATH	=			$(SRC_PATH)mini_game/

ANIM_PATH		=			$(SRC_PATH)animation/

EFFECT_PATH		=			$(SRC_PATH)effect/

FREE_PATH		=			$(SRC_PATH)free/

CSFML_PATH		=			$(SRC_PATH)csfml/

MATH_PATH		=			$(SRC_PATH)math/

MOUSE_PATH		=			$(SRC_PATH)mouse/

JSON_PATH		=			$(SRC_PATH)json/

## =========================[BASICS]==========================

UTILS_PATH		=			$(BASIC_PATH)utils/

EVENT_PATH		=			$(BASIC_PATH)event/

WIN_PATH		=			$(BASIC_PATH)window/

## ==========================[MENU]===========================

M_MENU_PATH		=			$(MENU_PATH)menu_main/

H_MENU_PATH		=			$(MENU_PATH)menu_howtoplay/

S_MENU_PATH		=			$(MENU_PATH)menu_settings/

## =========================[CSFML]===========================

TEXT_PATH		=			$(CSFML_PATH)texts/

SOUND_PATH		=			$(CSFML_PATH)sound/

BUTTON_PATH		=			$(CSFML_PATH)buttons/

## ========================[MINI_GAME]========================

POTION_PATH		=			$(MINGAME_PATH)potion/

## ========================[ANIMATION]========================

## =========================[EFFECTS]=========================

TEST_PATH		=			tests/

## ===================================================================
## ===============================[SRC]===============================
## ===================================================================

SRC_UTILS		=			$(UTILS_PATH)my_error_handling.c		\
							$(UTILS_PATH)my_help.c					\
							$(UTILS_PATH)files_manager.c			\

SRC_GAME		=			$(GAME_PATH)game_core.c					\

SRC_EVENT		=			$(EVENT_PATH)event.c					\

SRC_WINDOW		=			$(WIN_PATH)window.c					\

SRC_CSFML		=			$(CSFML_PATH)object.c					\
							$(CSFML_PATH)type_transformer.c			\
							$(TEXT_PATH)text.c						\
							$(TEXT_PATH)fonts.c						\
							$(SOUND_PATH)sound.c					\
							$(BUTTON_PATH)button_manage.c			\
							$(BUTTON_PATH)button_setup.c			\
							$(BUTTON_PATH)button_setup2.c			\
							$(BUTTON_PATH)button_utils.c			\

SRC_MATH		=			$(MATH_PATH)math.c						\

SRC_MOUSE		=			$(MOUSE_PATH)mouse.c					\

SRC_GLOBAL		=			$(SRC_UTILS)							\
							$(SRC_WINDOW)							\
							$(SRC_GAME)								\
							$(SRC_EVENT)							\
							$(SRC_CSFML)							\
							$(SRC_MATH)								\
							$(SRC_MOUSE)							\

SRC_JSON		=			$(JSON_PATH)generate/file_gestion.c			\
							$(JSON_PATH)generate/str_preprocessing.c	\
							$(JSON_PATH)generate/object_preprocessing.c	\
							$(JSON_PATH)generate/extract_fields.c		\
							$(JSON_PATH)generate/json_split.c			\
							$(JSON_PATH)generate/json_error_handling.c	\
							$(JSON_PATH)use/free_json.c					\
							$(JSON_PATH)use/json_get_by_name.c			\
							$(JSON_PATH)use/json_get_by_index.c			\
							$(JSON_PATH)use/json_display_obj.c			\
							$(JSON_PATH)use/main_json.c					\

SRC				=			$(SRC_GLOBAL)							\
							main.c

TEST_SRC		=			$(TEST_PATH)tests_error_handling.c		\

OBJ				=			$(SRC:.c=.o)

## ===================================================================
## =============================[OPTIONS]=============================
## ===================================================================

CFLAGS			=			-Wall -Wextra -g3

CPPFLAGS		=			-I include

LDFLAGS			=			-L lib -lmy							\
							-lcsfml-graphics -lcsfml-system 	\
							-lcsfml-audio -lcsfml-window		\
							-lm									\

CRIT			=			$(LDFLAGS) $(CPPFLAGS) -lcriterion --coverage

## =========================================================================
## =========================================================================
## =================================[RULES]=================================
## =========================================================================
## =========================================================================

all:	message
		make re -C lib/my
		make $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

re:			fclean	all

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
