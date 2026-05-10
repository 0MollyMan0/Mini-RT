# ==============
# LIBFT MAKEFILE
# ==============
NAME = libft.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC_DIR = .
OBJ_DIR = obj

# SOURCES
SRCS = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
       ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
       ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
       ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c \
       ft_toupper.c ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c \
       ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c \
       ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
       ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strcmp.c \
       ft_isspace.c ft_is_empty.c ft_utils_tab.c ft_add_char.c ft_strndup.c ft_atof.c \
       is_valid_double.c \

# OBJECTS
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

HEADER = -I.

# ==============================
# RULES
# ==============================

all: $(NAME)

# LIB
$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)

# Compilation of .c in .o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# Creation of folder obj
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# clean .o
clean:
	@rm -rf $(OBJ_DIR)

# clean .o and exe
fclean: clean
	@rm -f $(NAME)

# Rebuild
re: fclean all

# ==============================
# PHONY
# ==============================
.PHONY: all clean fclean re
