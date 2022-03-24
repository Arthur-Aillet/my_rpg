##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## MAKEFILE
##

## ==========================[THINGS_NOT_IMPORTANT]==========================

DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
RED_C	=	"\e[31m"
ECHO	=	/bin/echo -e
LINE_RETURN	=	$(ECHO) ""

## ==========================================================================
## ==========================================================================
## ===================================[VAR]==================================
## ==========================================================================
## ==========================================================================

NAME			=			my_rpg

NAME_TEST		=			unit_test

## ===================================================================
## ==============================[PATHS]==============================
## ===================================================================

## ===========================[SRC]===========================

SRC_PATH		=			src/

BASIC_PATH		=			$(SRC_PATH)basic/

INIT_PATH		=			$(SRC_PATH)init/

MENU_PATH		=			$(SRC_PATH)menu/

GAME_PATH		=			$(SRC_PATH)game/

MINGAME_PATH	=			$(SRC_PATH)mini_game/

ANIM_PATH		=			$(SRC_PATH)animation/

EFFECT_PATH		=			$(SRC_PATH)effect/

FREE_PATH		=			$(SRC_PATH)free/

CSFML_PATH		=			$(SRC_PATH)csfml/

MATH_PATH		=			$(SRC_PATH)math/

MOUSE_PATH		=			$(SRC_PATH)mouse/

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
							$(BUTTON_PATH)button_manage.c			\
							$(BUTTON_PATH)button_setup.c			\
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
		make clean -C lib/my
		rm -rf $(OBJ)

fclean:		clean
		make fclean -C lib/my
		rm -rf $(NAME)
		rm -rf $(NAME_TEST)
		rm -rf *gcda
		rm -rf *gcno

build_lib:

debug:

valgrind:

tests_run:
	make re -C lib/my
	gcc -o $(NAME_TEST) $(SRC_GLOBAL) $(SRC_TEST) $(TEST_SRC) $(CRIT)
	./$(NAME_TEST)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(RED_C)" _______________________________________________\
	_______________________________"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(RED_C)"|                                               \
	                               |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(RED_C)"|      _     _____   ____  ____   ____    __  __\
	 _____ _____ _____ _____       |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(RED_C)"|     | |   | ____| |  _ \|  _ \ / ___|  |  \/  \
	|  _  |_   _|  _  | ___ |      |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(RED_C)"|     | |   |  _|   | |_| | |_| | | |\   | |\/| \
	| |_| |_| | | | | |    _|      |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(RED_C)"|     | |___| |___  |  _  |  __/| |_| |  | |  | \
	|  _  | | | | |_| | |\ \       |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(RED_C)"|     |_____|_____| |_| \_\_|    \____|  |_|  |_\
	|_| |_|\__| |_____|_| \_|      |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(RED_C)"|                                               \
	                               |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(RED_C)"|_______________________________________________\
	_______________________________|"$(DEFAULT)
	@$(LINE_RETURN)
	@$(LINE_RETURN)

## ===========================================================
## ===========================[END]===========================
## ===========================================================

.PHONY:	all	re	clean	fclean	build_lib	debug	valgrind	tests_run	mes\
sage
