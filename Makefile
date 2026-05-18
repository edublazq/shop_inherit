################################################################################
#                            SHOP MAKEFILE                                    #
################################################################################

# ─────────────────── VARIABLES ───────────────────
NAME			=	shop
CC				=	g++
CFLAGS			=	-std=c++11 -Wall -Wextra -Werror
DEBUG_FLAGS		=	-g -O0
RELEASE_FLAGS	=	-O2

# Directorios
SRC_DIR			=	src
OBJ_DIR			=	obj
INC_DIR			=	include
BIN_DIR			=	.

# Archivos fuente
SRC_MAIN		=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/menu.cpp

SRC_CLASS		=	$(SRC_DIR)/class/Product.cpp \
				$(SRC_DIR)/class/Shop.cpp \
				$(SRC_DIR)/class/digitalGame.cpp \
				$(SRC_DIR)/class/physicalGame.cpp

SRC_ALL			=	$(SRC_MAIN) $(SRC_CLASS)

# Archivos objeto
OBJ				=	$(SRC_ALL:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Ruta del ejecutable
TARGET			=	$(BIN_DIR)/$(NAME)

# Colores
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
BLUE			=	\033[0;34m
CYAN			=	\033[0;36m
BOLD			=	\033[1m
NC				=	\033[0m

# ─────────────────── REGLAS ───────────────────

.PHONY: all clean fclean re debug release help

all: $(TARGET)
	@echo "$(GREEN)$(BOLD)✓ Build complete!$(NC)"

$(TARGET): $(OBJ)
	@echo "$(CYAN)Linking... $(NC)"
	@$(CC) $(CFLAGS) -o $@ $^ -I$(INC_DIR)
	@echo "$(GREEN)✓ Executable created: $(TARGET)$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/class
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(GREEN)✓ Object: $@$(NC)"

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean $(TARGET)
	@echo "$(BLUE)$(BOLD)Debug build complete$(NC)"

release: CFLAGS += $(RELEASE_FLAGS)
release: fclean $(TARGET)
	@echo "$(BLUE)$(BOLD)Release build complete$(NC)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✓ Object files removed$(NC)"

fclean: clean
	@echo "$(YELLOW)Removing executable...$(NC)"
	@rm -f $(TARGET)
	@echo "$(GREEN)✓ Everything cleaned$(NC)"

re: fclean all
	@echo "$(BLUE)$(BOLD)Rebuild complete$(NC)"

help:
	@echo "$(CYAN)$(BOLD)Available targets:$(NC)"
	@echo "  $(GREEN)make$(NC) or $(GREEN)make all$(NC)      - Build the project"
	@echo "  $(GREEN)make debug$(NC)               - Build with debug symbols"
	@echo "  $(GREEN)make release$(NC)             - Build optimized version"
	@echo "  $(GREEN)make clean$(NC)               - Remove object files"
	@echo "  $(GREEN)make fclean$(NC)              - Remove object files and executable"
	@echo "  $(GREEN)make re$(NC)                  - Clean rebuild"
	@echo "  $(GREEN)make help$(NC)                - Show this help message"

.SILENT: help
