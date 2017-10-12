NAME = wolf3d

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
OBJSUBDIR = obj/core obj/gui obj/tools

# Sources files
SRC_MAIN = \
		main.c\

SRC_CORE = \
		core/mlx.c\
		core/draw.c\
		core/init.c\
		core/compute.c\

SRC_GUI = \
		gui/mouse_hook.c\
		gui/key_hook.c\

SRC_TOOLS = \
		tools/error.c\

SRC = $(SRC_MAIN) $(SRC_CORE) $(SRC_GUI) $(SRC_TOOLS)

# Objects files
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

# Inludes and libraries
SYSTEM = $(shell uname -s)
ifeq ($(SYSTEM), Linux)
LIBMLX	=	-Llib/mlx/minilibx_$(SYSTEM) -lmlx -L/usr/lib -lXext -lX11 -lm -lpthread
else
SYSTEM = MACOS
LIBMLX	=	-Llib/mlx/minilibx_$(SYSTEM)/ -lmlx -framework OpenGL -framework AppKit
endif
LIBFT 	=	 -Llib/libft/ -lft
INC		=	-I inc/ -I lib/mlx/minilibx_$(SYSTEM)/ -I lib/libft/includes/\

# Rules
all: $(NAME)

$(NAME): obj libft $(OBJ)
		@echo "======================================="
		@printf "$(WHITE)Creating $(SYSTEM) $(NAME) executable... $(END_COLOR)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(LIBFT)
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
