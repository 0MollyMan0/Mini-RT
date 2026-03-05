# ==============================
# LIBFT MAKEFILE (bonus intégré)
# ==============================
NAME = libft.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC_DIR = .
OBJ_DIR = obj

# SOURCES principales + "bonus"
SRCS = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
       ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
       ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
       ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c \
       ft_toupper.c ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
       ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
       ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
       ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
       ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_strcmp.c

# OBJETS
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

HEADER = -I.

# ==============================
# REGLES
# ==============================

all: $(NAME)

# Archiver la lib
$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "\033[1;34m[LIBFT] -> Creating $(NAME)...\033[0m"
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[1;32m[OK] -> $(NAME) ready!\033[0m"

# Compilation des .c en .o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@echo "\033[1;33m[CC] -> $<\033[0m"
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# Création du dossier obj si nécessaire
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Nettoyage des objets
clean:
	@echo "\033[1;31m[CLEAN] -> Removing object files...\033[0m"
	@rm -rf $(OBJ_DIR)

# Nettoyage complet
fclean: clean
	@echo "\033[1;31m[FCLEAN] -> Removing archive...\033[0m"
	@rm -f $(NAME)

# Rebuild complet
re: fclean all

# ==============================
# PHONY
# ==============================
.PHONY: all clean fclean re
