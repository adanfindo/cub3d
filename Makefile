# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afindo <afindo@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 11:16:12 by afindo          #+#    #+#              #
#    Updated: 2022/09/13 13:03:39 by afindo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3D

COMPILER 	= cc
CFLAGS 		= -Wall -Wextra -Werror

MYLIBS 		= libft/libft.a
LIBS 		= -lm

SRCS_PATH 	= 	./src/
EXIT		= 	exit/
HOOKS		=	hooks/
INIT		=	init/
MOVE 		=	move/
RENDER		=	render/
UTILS		=	utils/


SRCS_NAMES	= 	main \
				$(EXIT)exit \
				$(EXIT)free \
				$(HOOKS)keyhooks \
				$(HOOKS)mousehooks \
				$(HOOKS)open_door \
				$(HOOKS)others \
				$(INIT)check_map_init_player \
				$(INIT)init \
				$(INIT)parse_map_file \
				$(INIT)parse_map_properties \
				$(INIT)parse_map_tiles \
				$(INIT)parse_map_floor_ceiling \
				$(INIT)parse_map_wall1 \
				$(INIT)parse_map_wall2 \
				$(INIT)player_init \
				$(MOVE)move \
				$(MOVE)translate \
				$(RENDER)draw \
				$(RENDER)raycast \
				$(RENDER)render_minimap \
				$(RENDER)render_pov \
				$(RENDER)render_scene \
				$(UTILS)hashtable1 \
				$(UTILS)hashtable2 \
				$(UTILS)math \
				$(UTILS)utils_parse \
				$(UTILS)utils_general1 \
				$(UTILS)utils_general2 \
				$(UTILS)utils_rendering \

OS = $(shell uname)
ifeq ($(OS), Linux)
	LIBS += -lmlx -lX11 -lXext
	SRCS_NAMES += $(EXIT)destroy_linux
endif
ifeq ($(OS), Darwin)
	LIBS +=  mlx/libmlx.a -L./mlx/ -lmlx -framework OpenGL -framework AppKit
	SRCS_NAMES += $(EXIT)destroy_mac
endif

OBJS_PATH	= 	./obj/
OBJS_NAMES	= 	$(SRCS_NAMES:%=%.o)
OBJS		= 	$(addprefix $(OBJS_PATH), $(OBJS_NAMES))

ALL_DIRS	= 	$(EXIT) $(HOOKS) $(INIT) $(MOVE) $(RENDER) $(UTILS)
DIRS_PATHS	=	$(addprefix $(OBJS_PATH), $(ALL_DIRS))

all: $(NAME)

$(NAME): $(OBJS) $(MYLIBS)
	$(COMPILER) $(CFLAGS) $(OBJS) $(MYLIBS) $(LIBS) -o $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	mkdir -p $(OBJS_PATH)
	mkdir -p $(DIRS_PATHS)
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(MYLIBS): FORCE
	make -C $(dir $@)

FORCE: ;

clean:
	rm -rf $(OBJS_PATH)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

bonus: all