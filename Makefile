# ----------------------------------
# PROJECT NAME
# ----------------------------------
NAME = miniRT

# ----------------------------------
# COMPILATION AND FLAGS
# ----------------------------------
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I ./ -I lib/gnl

# ----------------------------------
# PATH
# ----------------------------------
SRC_DIR    = src
GRAPH_DIR  = $(SRC_DIR)/graph_engine
RANDOM_DIR  = $(SRC_DIR)/random
PARSE_DIR  = $(SRC_DIR)/parsing
VERIF_PARSE_DIR = $(PARSE_DIR)/verif_parsing
OBJ_DIR    = obj
LIBFT_DIR  = lib/libft
GNL_DIR    = lib/gnl
MLX_DIR    = lib/minilibx-linux

# ----------------------------------
# COLORS
# ----------------------------------
# NORMAL
RESET       = \033[0m
BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m
# BOLD
BRESET       = \033[1m
BBLACK       = \033[1;30m
BRED         = \033[1;31m
BGREEN       = \033[1;32m
BYELLOW      = \033[1;33m
BBLUE        = \033[1;34m
BMAGENTA     = \033[1;35m
BCYAN        = \033[1;36m
BWHITE       = \033[1;37m

# ----------------------------------
# SOURCES
# ----------------------------------
GNL_SRC = $(GNL_DIR)/get_next_line.c \
		  $(GNL_DIR)/get_next_line_utils.c

SRC = $(SRC_DIR)/main.c \
		$(RANDOM_DIR)/exit.c \
		$(RANDOM_DIR)/init.c \
		$(RANDOM_DIR)/init_helpers.c \
		$(RANDOM_DIR)/print_error.c \
		$(RANDOM_DIR)/random_utils.c \
		$(RANDOM_DIR)/objects_lst.c \
		$(PARSE_DIR)/parsing_objects.c \
		$(PARSE_DIR)/parsing_scene.c \
		$(PARSE_DIR)/parsing_utils.c \
		$(PARSE_DIR)/parsing.c \
		$(VERIF_PARSE_DIR)/parsing_verif_object.c \
		$(VERIF_PARSE_DIR)/parsing_verif_scene.c \
		$(VERIF_PARSE_DIR)/parsing_verif_syntax.c \
		$(VERIF_PARSE_DIR)/parsing_verif_utils.c \
		$(VERIF_PARSE_DIR)/parsing_verif.c \
		$(GRAPH_DIR)/rays.c \
		$(GRAPH_DIR)/render_utils.c \
		$(GRAPH_DIR)/render.c \
		$(GRAPH_DIR)/sphere.c \
		$(GRAPH_DIR)/cylinder.c \
		$(GRAPH_DIR)/plane.c \
		$(GRAPH_DIR)/controls.c \
		$(GRAPH_DIR)/vec_utils.c \
		$(GNL_SRC)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ----------------------------------
# LIBRARIES
# ----------------------------------
LIBFT = $(LIBFT_DIR)/libft.a
MLX   = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# ----------------------------------
# RULES
# ----------------------------------

all: $(LIBFT) $(NAME) banner

banner :
	@echo "███╗   ███╗██╗███╗   ██╗██╗      ██████╗ ████████╗"
	@echo "████╗ ████║██║████╗  ██║██║      ██╔══██╗╚══██╔══╝"
	@echo "██╔████╔██║██║██╔██╗ ██║██║█████╗██████╔╝   ██║   "
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║╚════╝██╔══██╗   ██║   "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║      ██║  ██║   ██║   "
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝      ╚═╝  ╚═╝   ╚═╝   "

# Final link : libft + MLX
$(NAME): $(OBJ)
	@echo "$(CYAN)[LINK] -> Creating $(NAME)...$(RESET)"
	@$(CC) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(BGREEN)[OK] -> $(NAME) ready!$(RESET)"

# Compilation of .c in .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(CYAN)[COMPILING]$(RESET) $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

# Create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilation of libft
$(LIBFT):
	@echo "$(CYAN)[LIBFT] -> Compiling libft...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "$(BGREEN)[OK] -> libft ready!$(RESET)"

# Clean
clean:
	@echo "$(BRED)[CLEAN] -> Removing object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C lib/libft clean

# Full Clean
fclean: clean
	@echo "$(BRED)[FCLEAN] -> Removing executable...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -s -C lib/libft fclean

# Rebuild
re: fclean all

# ----------------------------------
# PHONY
# ----------------------------------
.PHONY: all clean fclean re
