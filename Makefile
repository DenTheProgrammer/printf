NAME = libftprintf.a

# compiling

CPP = gcc -g -c

# paths

SRC_DIR	= srcs/
OBJ_DIR = obj/
LIB_DIR = libft/

# files

SRC =	addit.c                                         output.c            \
            apply_flags.c           flist.c                 parse_arguments.c   \
            apply_formats.c         float.c                 power.c             \
            apply_precision.c       fract.c                 start.c             \
            apply_specific_format.c ft_printf.c             throw_error.c       \
            apply_width.c           mult.c                  whole.c

OBJ = $(patsubst %.c, %.o, $(SRC))
HEADER = -I includes
LIB = libft/libft.a

# files with dir

C_PATH = $(addprefix $(SRC_DIR), $(SRC))
O_PATH = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(O_PATH)
	cp $(LIB) ./$(NAME)
	ar -rc $(NAME) $(O_PATH)
	ranlib $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CPP) $< -o $@ $(HEADER) -I $(LIB_DIR)

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all fclean clean re
