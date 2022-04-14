##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## MAKEFILE
##

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

CC				=			gcc

RM				=			rm -rf

NAME_TEST		=			unit_test

## ===================================================================
## ==============================[PATHS]==============================
## ===================================================================

## ===========================[SRC]===========================

SRC_PATH		=			src/

BASIC_PATH		=			$(SRC_PATH)basic/

INIT_PATH		=			$(SRC_PATH)init/

UI_PATH			=			$(SRC_PATH)ui/

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

INVENTORY_PATH	=			$(SRC_PATH)inventory/

PARTICLES_PATH	= 			$(SRC_PATH)particle_system/

DIALOGUE_PATH	=			$(SRC_PATH)dialogue/

## =========================[BASICS]==========================

UTILS_PATH		=			$(BASIC_PATH)utils/

WIN_PATH		=			$(BASIC_PATH)window/

KEY_PATH		=			$(BASIC_PATH)keyboard/

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

SRC_KEY			=			$(KEY_PATH)keyboard_input.c				\
							$(KEY_PATH)keyboard_input_init.c		\

SRC_POTION		=			$(POTION_PATH)potions_loop.c			\
							$(POTION_PATH)hammer_minigame1.c		\
							$(POTION_PATH)hammer_minigame2.c		\
							$(POTION_PATH)minigame.c				\
							$(POTION_PATH)mortar_minigame1.c		\

SRC_UI			=			$(UI_PATH)display_healthbar.c			\
							$(UI_PATH)display_ui.c

SRC_INVENTORY	=			$(INVENTORY_PATH)draw_items.c			\
							$(INVENTORY_PATH)get_positions.c		\
							$(INVENTORY_PATH)get_slots.c			\
							$(INVENTORY_PATH)inventory_displays.c	\
							$(INVENTORY_PATH)inventory_events.c		\
							$(INVENTORY_PATH)inventory_interactions.c	\
							$(INVENTORY_PATH)inventory_setups.c		\
							$(INVENTORY_PATH)inventory_swaps.c		\
							$(INVENTORY_PATH)is_adjacent_competences.c	\
							$(INVENTORY_PATH)inventory.c					\
							$(INVENTORY_PATH)temp_main.c			\

SRC_DIALOGUE	=			$(DIALOGUE_PATH)dialogue.c				\
							$(DIALOGUE_PATH)dialogue_utils.c		\

SRC_PARTICLES	=			$(PARTICLES_PATH)particle_system_execution.c	\
							$(PARTICLES_PATH)creation.c				\
							$(PARTICLES_PATH)destruction.c			\
							$(PARTICLES_PATH)particles/dust.c		\
							$(PARTICLES_PATH)particles/electricity.c\
							$(PARTICLES_PATH)particles/fire.c		\
							$(PARTICLES_PATH)particles/snow.c		\
							$(PARTICLES_PATH)particles/spark.c		\
							$(PARTICLES_PATH)particles/water.c		\
							$(PARTICLES_PATH)particles/leaves.c		\

SRC_WINDOW		=			$(WIN_PATH)window.c						\

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
							$(JSON_PATH)use/json_main.c					\

SRC_GLOBAL		=			$(SRC_UTILS)							\
							$(SRC_WINDOW)							\
							$(SRC_GAME)								\
							$(SRC_EVENT)							\
							$(SRC_POTION)							\
							$(SRC_INVENTORY)						\
							$(SRC_PARTICLES)						\
							$(SRC_DIALOGUE)							\
							$(SRC_UI)								\
							$(SRC_JSON)								\
							$(SRC_CSFML)							\
							$(SRC_MATH)								\
							$(SRC_MOUSE)							\
							$(SRC_KEY)								\

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
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

re:			fclean	all

clean:
		make clean -C lib/my
		$(RM) $(OBJ)

fclean:		clean
		make fclean -C lib/my
		$(RM) $(NAME)
		$(RM) $(NAME_TEST)
		find . -name "*.gc*" -exec $(RM) {} \;

build_lib:

debug:

valgrind:	$(CFLAGS) += -g
valgrind:	re

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
