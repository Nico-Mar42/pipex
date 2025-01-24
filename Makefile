# Variables
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIB_DIR = lib
NAME = pipex

# Bibliothèques
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

# Sources et objets
ALL_SRC = main.c \
		utils.c \
		free_data.c \
		children.c \
		here_doc.c 
SRC = $(addprefix $(SRC_DIR)/, $(ALL_SRC))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Règle par défaut
all: $(LIBFT_LIB) $(NAME)

# Compilation de la libft
$(LIBFT_LIB):
	@echo "Building Libft..."
	$(MAKE) -C $(LIBFT_DIR)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Création de l'exécutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT_FLAGS)

# Nettoyage
clean:
	@rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
