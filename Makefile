# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/06 22:40:14 by vchaillo          #+#    #+#              #
#    Updated: 2017/04/01 21:11:11 by valentinchaillou89###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -Rf

# Colors
GREY = \033[30;1m
RED = \033[31;1m
GREEN =	\033[32;1m
YELLOW = \033[33;1m
BLUE = \033[34;1m
WHITE = \033[37;1m
END_COLOR =	\033[0m

# Directories
SRCDIR = src/
OBJDIR = obj/
OBJSUBDIR = obj/core obj/gui obj/cli obj/tools obj/structs\
			obj/scenes obj/parser obj/export

# Sources files
SRC_MAIN = \
		main.c\

SRC_CORE = \
		core/raytracer.c\
		core/light.c\
		core/normal.c\
		core/sphere.c\
		core/plane.c\
		core/cylinder.c\
		core/cone.c\
		core/box.c\
		core/disc.c\
		core/tore.c\
		core/boloid.c\
		core/effects.c\
		core/depth_compute.c\
		core/reflection.c\
		core/refraction.c\
		core/global_illumination.c\
		core/antialiasing.c\
		core/multithreading.c\
		core/perlin.c\
		core/exposure.c\
		core/fog.c\
		core/stereoscopy.c\

SRC_PARSER = \
		parser/args_parser.c\
		parser/parse_macros.c\
		parser/parser_tools.c\
		parser/parser.c\
		parser/get_macros.c\
		parser/create.c\

SRC_GUI = \
		gui/mlx.c\
		gui/key_hook.c\
		gui/key_hook_camera.c\
		gui/key_hook_objects.c\
		gui/key_hook_cylinder.c\
		gui/key_hook_cone.c\
		gui/key_hook_box.c\
		gui/key_hook_disc.c\
		gui/mouse_hook.c\
		gui/print.c\
		gui/draw.c\

SRC_CLI = \
		cli/output.c\
		cli/hooks_output.c\

SRC_TOOLS = \
		tools/utils.c\
		tools/vector.c\
		tools/rotations.c\
		tools/solve_equations.c\
		tools/color.c\
		tools/error.c\
		tools/cross_product.c\
		tools/ft_putfloat.c\
		tools/ft_putfloat_fd.c\

SRC_EXPORT = \
		export/exports.c\
		export/export_image.c\
		export/export_scene.c\
		export/export_objects.c\
		export/export_objects2.c\
		export/export_lights.c\
		export/export_tools.c\

SRC_SCENES = \
		scenes/scenes.c\
		scenes/scene1.c\
		scenes/scene2.c\
		scenes/scene3.c\
		scenes/scene4.c\
		scenes/scene5.c\
		scenes/scene6.c\
		scenes/scene7.c\
		scenes/scene8.c\
		scenes/scene9.c\

SRC_STRUCTS = \
		structs/t_vector.c\
		structs/t_scene.c\
		structs/t_camera.c\
		structs/t_sphere.c\
		structs/t_plane.c\
		structs/t_tore.c\
		structs/t_boloid.c\
		structs/t_cylinder.c\
		structs/t_cone.c\
		structs/t_box.c\
		structs/t_disc.c\
		structs/t_object.c\
		structs/t_light.c\
		structs/t_material.c\
		structs/t_material2.c\
		structs/t_color.c\
		structs/t_color_array.c\

SRC = $(SRC_MAIN) $(SRC_CORE) $(SRC_GUI) $(SRC_CLI)\
 		$(SRC_TOOLS) $(SRC_STRUCTS) $(SRC_SCENES) $(SRC_PARSER) $(SRC_EXPORT)\

# Objects files
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

# Inludes and libraries
SYSTEM = $(shell uname -s)
ifeq ($(SYSTEM), Linux)
LIBMLX	=	-Llib/mlx/minilibx_$(SYSTEM) -lmlx -L/usr/lib -lXext -lX11 -lm -lpthread
LIBGSL	=	-Llib/gsl/gsl_$(SYSTEM)/lib -lgsl -lgslcblas
else
SYSTEM = MACOS
LIBMLX	=	-Llib/mlx/minilibx_$(SYSTEM)/ -lmlx -framework OpenGL -framework AppKit
LIBGSL	=	-Llib/gsl/gsl_$(SYSTEM)/lib -lgsl -lgslcblas
endif
LIBFT 	=	 -Llib/libft/ -lft
INC		=	-I inc/ -I lib/mlx/minilibx_$(SYSTEM)/ -I lib/libft/includes/\
			-I lib/gsl/gsl_$(SYSTEM)/include/

# Rules
all: $(NAME)

$(NAME): obj libft $(OBJ)
		@echo "======================================="
		@printf "$(WHITE)Creating $(SYSTEM) $(NAME) executable... $(END_COLOR)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(LIBFT) $(LIBGSL)
		@echo "$(GREEN)Done √$(END_COLOR)"
		@echo "======================================="

DEPS := $(OBJ:.o=.d)
-include $(DEPS)
$(OBJDIR)%.o:$(SRCDIR)%.c
		@$(CC) $(CFLAGS) -MD $(INC) -o $@ -c $<
		@echo "[$(GREEN)√$(END_COLOR)]" $(subst obj/,src/,$(subst .o,.c,$@))

obj:
		@mkdir -p $(OBJDIR)
		@mkdir -p $(OBJSUBDIR)

libft:
		@make -sC lib/libft/ 2>&-

clean:
		@$(RM) $(OBJ)
		@$(RM) $(OBJDIR)
		@echo "$(BLUE)$(NAME)$(GREY) - Cleaning object files$(END_COLOR)"

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(BLUE)$(NAME)$(GREY) - Cleaning executables$(END_COLOR)"
		@make -sC lib/libft/ fclean 2>&-

norm:
		@echo "$(BLUE)Norminette...$(END_COLOR)"
		@norminette inc src

re: fclean all

.PHONY: all obj libft clean fclean norm re
