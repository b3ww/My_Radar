##
## EPITECH PROJECT, 2022
## bootstrap
## File description:
## Makefile
##

CC	=	gcc

SRC		=	src/main.c \
			src/mainloop.c \
			src/mgetnbr.c \
			src/init_elements.c \
			src/draw_elements.c \
			src/update_elements.c \
			src/update_planes.c \
			src/plane_orientation.c \
			src/check_alive.c \
			src/colision.c \
			src/in_tower.c \
			src/main_play.c \
			src/menu.c \
			src/reload_game.c \
			src/menu_init.c \
			src/mpstr.c \
			src/timer.c \
			src/destroy_elements.c \
			src/script_parsing/main.c \
			src/script_parsing/get_script_content.c \
			src/script_parsing/split_in_lines.c \
			src/script_parsing/mstr_to_word_array.c \
			src/script_parsing/get_elements.c \
			src/script_parsing/get_plane_infos.c \
			src/script_parsing/get_tower_infos.c \
			src/quad_tree/split_area.c \
			src/quad_tree/init_area.c \
			src/quad_tree/get_plane_in_area.c \

OBJ		=	$(SRC:.c=.o)

NAME	=	my_radar

CFLAGS	=	-l csfml-graphics -l csfml-system -l csfml-window \
			-I./includes -lm

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)

re:     fclean all fclean

.PHONY: all clean fclean re

.SILENT: all clean fclean re $(OBJ)
