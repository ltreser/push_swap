NAME = push_swap

SRC = lis.c  array_utils.c  main.c  back2a_exec.c  init.c  optimizer.c \
      back2a_init.c instructions.c instructionss.c instructionsss.c \
      parse_and_index.c  sleepy.c  deque_utils.c  tiny_sort.c  error_free.c \
      push_swap.c  divider_algo.c \

SRC_DIR = src/

OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

INC_DIR = include/

HEADERS = $(addprefix $(INC_DIR), push_swap.h)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -Iinclude/ -I/usr/include

LDLIBS = -lft

LDFLAGS = -L libft

RM = rm -rf

LIBFT = libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I/usr/include -c $< -o $@

$(LIBFT):
	make -C ./libft

$(NAME): $(HEADERS) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re flclean clean all
