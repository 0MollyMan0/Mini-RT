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
PARSE_DIR  = $(SRC_DIR)/parsing
OBJ_DIR    = obj
LIBFT_DIR  = lib/libft
GNL_DIR    = lib/gnl
MLX_DIR    = lib/minilibx-linux

# ----------------------------------
# COLORS
# ----------------------------------
RESET       = \033[0m
BLACK       = \033[0;30m
RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
WHITE       = \033[0;37m

# ----------------------------------
# SOURCES
# ----------------------------------
GNL_SRC = $(GNL_DIR)/get_next_line.c \
		  $(GNL_DIR)/get_next_line_utils.c

SRC = $(SRC_DIR)/main.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/render.c \
		$(SRC_DIR)/render_utils.c \
		$(SRC_DIR)/controls.c \
		$(SRC_DIR)/exit.c \
		$(SRC_DIR)/sphere.c \
		$(SRC_DIR)/rays.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/parsing_utils.c \
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
	@echo "$(GREEN)[OK] -> $(NAME) ready!$(RESET)"

# Compilation of .c in .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(CYAN)[COMPILING]$(RESET) $<"
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

# Create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilation of libft
$(LIBFT):
	@echo "$(CYAN)[LIBFT] -> Compiling libft...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "$(GREEN)[OK] -> libft ready!$(RESET)"

# Clean
clean:
	@echo "$(RED)[CLEAN] -> Removing object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C lib/libft clean

# Full Clean
fclean: clean
	@echo "$(RED)[FCLEAN] -> Removing executable...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -s -C lib/libft fclean

# Rebuild
re: fclean all

# ----------------------------------
# PHONY
# ----------------------------------
.PHONY: all clean fclean re
