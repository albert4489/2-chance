NAME = pathfinder
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

LIBA = libmx.a
LIBR = libmx
LIB = $(LIBR)/$(LIBA)

SRCD = src
INCD = inc
OBJD = obj

SRC = $(wildcard $(SRCD)/*.c)
OBJ = $(addprefix $(OBJD)/,$(notdir $(SRC:.c=.o)))

all: $(SRC) $(NAME)

create_objdir:
	mkdir -p $(OBJD)

$(NAME): create_objdir $(OBJ)
	make -C $(LIBR)
	$(CC) $(CFLAGS) $(OBJ) -Llibmx -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

uninstall: clean
	rm -rf $(NAME)
	make -C $(LIBR) uninstall

clean:
	rm -rf $(OBJD)
	make -C $(LIBR) clean

reinstall: uninstall all


.PHONY: all clean uninstall reinstall
