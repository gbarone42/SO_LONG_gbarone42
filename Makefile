NAME = so_long

SRCS = ARCADE/main.c \
		ARCADE/control.c \
		ARCADE/animation.c \
		ARCADE/maps_check.c \
		ARCADE/map_check_tools.c \
		ARCADE/char_tool.c \
		ARCADE/map_generator.c \
		ARCADE/guards_creator.c \
		ARCADE/guards_creator2.c \
		ARCADE/image_creator.c \
		ARCADE/player_init.c \
		ARCADE/handle_manager.c \
		ARCADE/updater.c \
		ARCADE/updater_2.c \
		ARCADE/release_memory.c \
		ARCADE/game_over.c \

SRCSb = ARCADEb/main.c \
		ARCADEb/control.c \
		ARCADEb/animation.c \
		ARCADEb/maps_check.c \
		ARCADEb/map_check_tools.c \
		ARCADEb/char_tool.c \
		ARCADEb/map_generator.c \
		ARCADEb/guards_creator.c \
		ARCADEb/guards_creator2.c \
		ARCADEb/image_creator.c \
		ARCADEb/player_init.c \
		ARCADEb/handle_manager.c \
		ARCADEb/updater.c \
		ARCADEb/updater_2.c \
		ARCADEb/release_memory.c \
		ARCADEb/game_over.c \


OBJS = $(SRCS:.c=.o)

OBJSb = $(SRCSb:.c=.o)

LIBS = ARCADE/libftprintf.a \
		ARCADE/GNL.a \
		ARCADE/libmlx.a \
		ARCADE/libmlx_Linux.a \

LIBSb = ARCADEb/libftprintf.a \
		ARCADEb/GNL.a \
		ARCADEb/libmlx.a \
		ARCADEb/libmlx_Linux.a \

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MFLAGS = -lX11 -lXext -lm
CORSIVO='\033[3m'
GREEN='\033[32m'
GRAY='\033[2;37m'

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MFLAGS) -o $(NAME) -g

play:	all
	@echo $(CORSIVO)"     - Playing all maps... \n"$(GRAY)
	@make -C ./ clean
	@./$(NAME) ./maps/level_1.ber
	@./$(NAME) ./maps/level_2.ber
	@./$(NAME) ./maps/level_3.ber
	@./$(NAME) ./maps/level_4.ber
	
clean:
		$(RM) $(OBJS)
		$(RM) $(OBJSb)

fclean: clean
	@echo $(GREEN)"     - Removing object files..."
			$(RM) $(NAME)

re: fclean $(NAME)

bonus: $(OBJSb)
		$(CC) $(CFLAGS) $(OBJSb) $(LIBSb) $(MFLAGS) -o $(NAME) -g


playb:	bonus
	@echo $(CORSIVO)"     - Playing all maps... \n"$(GRAY)
	@make -C ./ clean
	@./$(NAME) ./maps/level_1.ber
	@./$(NAME) ./maps/level_2.ber
	@./$(NAME) ./maps/level_3.ber
	@./$(NAME) ./maps/level_4.ber

.PHONY: all clean fclean re


