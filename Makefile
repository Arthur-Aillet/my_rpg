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

NAME_TEST		=			unit_test

## ===================================================================
## ==============================[PATHS]==============================
## ===================================================================

## ===========================[SRC]===========================

SRC_PATH		=			src/

BASIC_PATH		=			$(SRC_PATH)basic/

CSFML_PATH		=			$(SRC_PATH)csfml/

DIALOGUE_PATH	=			$(SRC_PATH)dialogue/

GAME_PATH		=			$(SRC_PATH)game/

INIT_PATH		=			$(SRC_PATH)init/

INVENTORY_PATH	=			$(SRC_PATH)inventory/

JSON_PATH		=			$(SRC_PATH)json/

MATH_PATH		=			$(SRC_PATH)math/

MINGAME_PATH	=			$(SRC_PATH)mini_game/

MOUSE_PATH		=			$(SRC_PATH)mouse/

PARTICLES_PATH	= 			$(SRC_PATH)particle_system/

UI_PATH			=			$(SRC_PATH)ui/

TEST_PATH		=			tests/

## ===================================================================
## ===============================[SRC]===============================
## ===================================================================

SRC_BASICS		=			$(BASIC_PATH)utils/my_error_handling.c		\
							$(BASIC_PATH)utils/my_help.c				\
							$(BASIC_PATH)utils/files_manager.c			\
							$(BASIC_PATH)window/window.c				\
							$(BASIC_PATH)keyboard/keyboard_input.c		\
							$(BASIC_PATH)keyboard/keyboard_input_init.c	\

SRC_CSFML		=			$(CSFML_PATH)object.c						\
							$(CSFML_PATH)type_transformer.c				\
							$(CSFML_PATH)texts/text.c					\
							$(CSFML_PATH)texts/fonts.c					\
							$(CSFML_PATH)sound/sound.c					\
							$(CSFML_PATH)buttons/button_manage.c		\
							$(CSFML_PATH)buttons/button_setup.c			\
							$(CSFML_PATH)buttons/button_setup2.c		\
							$(CSFML_PATH)buttons/button_utils.c			\

SRC_DIALOGUE	=			$(DIALOGUE_PATH)dialogue.c					\
							$(DIALOGUE_PATH)dialogue_utils.c			\

SRC_POTION		=			$(POTION_PATH)potions_loop.c				\
							$(POTION_PATH)hammer_minigame.c				\
							$(POTION_PATH)minigame.c					\
							$(POTION_PATH)mortar_minigame1.c			\

SRC_GAME		=			$(GAME_PATH)game_core.c						\
							$(GAME_PATH)game_loop.c						\
							$(GAME_PATH)display/my_display_world.c		\
							$(GAME_PATH)display/my_display_map.c		\
							$(GAME_PATH)display/my_display_player.c		\
							$(GAME_PATH)actions/player/player_action.c	\
							$(GAME_PATH)actions/player/player_move.c	\

SRC_INIT		=			$(INIT_PATH)init_game_struct.c				\
							$(INIT_PATH)init_game_status.c				\
							$(INIT_PATH)init_in_game_struct.c			\
							$(INIT_PATH)init_map_objects.c				\

SRC_INVENTORY	=			$(INVENTORY_PATH)draw_items.c				\
							$(INVENTORY_PATH)get_positions.c			\
							$(INVENTORY_PATH)get_slots.c				\
							$(INVENTORY_PATH)inventory_displays.c		\
							$(INVENTORY_PATH)inventory_events.c			\
							$(INVENTORY_PATH)inventory_interactions.c	\
							$(INVENTORY_PATH)inventory_setups.c			\
							$(INVENTORY_PATH)inventory_swaps.c			\
							$(INVENTORY_PATH)is_adjacent_competences.c	\
							$(INVENTORY_PATH)inventory.c				\
							$(INVENTORY_PATH)temp_main.c				\

SRC_JSON		=			$(JSON_PATH)generate/reader/file_gestion.c			\
							$(JSON_PATH)generate/reader/str_preprocessing.c		\
							$(JSON_PATH)generate/reader/object_preprocessing.c	\
							$(JSON_PATH)generate/reader/extract_fields.c		\
							$(JSON_PATH)generate/reader/json_split.c			\
							$(JSON_PATH)generate/reader/json_error_handling.c	\
							$(JSON_PATH)use/get/json_get_by_name.c				\
							$(JSON_PATH)use/get/json_get_by_index.c				\
							$(JSON_PATH)use/get/json_display_obj.c				\
							$(JSON_PATH)use/json_main.c							\
																				\
							$(JSON_PATH)use/edit/json_add_field.c				\
							$(JSON_PATH)use/edit/json_edit_by_name.c			\
							$(JSON_PATH)use/edit/manage_json.c					\
							$(JSON_PATH)generate/reader/duplicate_data.c		\
							$(JSON_PATH)generate/reader/allocation.c			\
																				\
							$(JSON_PATH)dependencies/chain_chars.c				\

SRC_MATH		=			$(MATH_PATH)math.c							\

SRC_KEY			=			$(KEY_PATH)keyboard_input.c					\
							$(KEY_PATH)keyboard_input_init.c			\

SRC_MINIGAME	=			$(MINGAME_PATH)hammer_minigame1.c			\
							$(MINGAME_PATH)hammer_minigame2.c			\

SRC_MOUSE		=			$(MOUSE_PATH)mouse.c						\

SRC_PARTICLES	=			$(PARTICLES_PATH)particle_system_execution.c	\
							$(PARTICLES_PATH)creation.c					\
							$(PARTICLES_PATH)destruction.c				\
							$(PARTICLES_PATH)particles/dust.c			\
							$(PARTICLES_PATH)particles/fire.c			\
							$(PARTICLES_PATH)particles/snow.c			\
							$(PARTICLES_PATH)particles/spark.c			\
							$(PARTICLES_PATH)particles/water.c			\
							$(PARTICLES_PATH)particles/leaves.c			\
							$(PARTICLES_PATH)particles/electricity.c	\

SRC_UI			=			$(UI_PATH)display_healthbar.c				\
							$(UI_PATH)display_ui.c						\

SRC_GLOBAL		=			$(SRC_BASICS)								\
							$(SRC_CSFML)								\
							$(SRC_DIALOGUE)								\
							$(SRC_GAME)									\
							$(SRC_INIT)									\
							$(SRC_INVENTORY)							\
							$(SRC_JSON)									\
							$(SRC_MATH)									\
							$(SRC_MINIGAME)								\
							$(SRC_MOUSE)								\
							$(SRC_PARTICLES)							\
							$(SRC_UI)									\

SRC				=			$(SRC_GLOBAL)								\
							main.c

TEST_SRC		=			$(TEST_PATH)tests_error_handling.c			\

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

all:
		make message
		make $(NAME)

$(NAME):	build_lib	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

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
		make re -C lib/my

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
