# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 13:20:49 by lbatista          #+#    #+#              #
#    Updated: 2023/09/19 00:09:57 by mvavasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL		=	all

NAME				=	cub3D

SRC_DIR				=	src
SRC_FILES			=	main.c \
						queue.c \
						exit_error.c \
						get_map_file.c \
						free_map_file.c \
						check_file.c \
						get_file_content.c \
						has_content.c \
						count_char.c \
						check_texture.c \
						check_color.c \
						get_color.c \
						load_textures.c \
						get_matrix_map.c \
						check_empty.c \
						define_map_sizes.c \
						check_map_edges.c \
						is_in_set.c \
						format_map.c \
						load_map.c \
						check_player.c \
						free_data.c \
						init_player.c \
						deg_to_rad.c \
						setup.c \
						key_hook.c \
						normalize_angle.c \
						distance_between_points.c \
						draw_pixel.c \
						get_pixel.c \
						has_wall_at.c \
						is_ray_facing.c \
						is_inside_map.c \
						cast_ray.c \
						cast_all_rays.c \
						update.c \
						render.c \
						game.c

OBJ_DIR				=	obj
OBJ_FILES			=	$(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

LIBFT_DIR			=	libft
LIBFT_LIB			=	-L$(LIBFT_DIR) -lft
LIBFT_INC			=	-I $(LIBFT_DIR)/includes

LIBS				=	-lmlx -lbsd -lXext -lX11 -lm $(LIBFT_LIB)

CC					=	cc
CFLAGS				=	-g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBS) $(LIBFT_INC) -o $(NAME)
	@ echo -e '\033[0;32m[SUCCESS]\033[0m Compilation done!'

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make $@ -C $(LIBFT_DIR)
	@ echo -e '\033[0;33mObjects removed\033[0m'

fclean: clean
	@rm -f $(NAME)
	@make $@ -C $(LIBFT_DIR)
	@ echo -e '\033[0;33mEverything is clean\033[0m'

valgrind:
			@echo "$(WHT)Removing old log.$(EOC)"
			@rm -f valgrind-out.txt
			@echo "$(WHT)Old log removed.$(EOC)"
			@echo "$(WHT)Executing Valgrind.$(EOC)"
			@valgrind --leak-check=full --show-leak-kinds=reachable --track-origins=yes \
			--log-file=valgrind-out.txt \
			./cub3D maps/teste.cub
			@echo "$(GREEN)Valgrind-log created.$(EOC)"

re: fclean all

.PHONY: all clean fclean re
