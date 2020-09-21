CC = gcc

FLAGS = -Wall -Wextra -Werror -lm
#FLAGS = -Wall

SAN = -fsanitize=leak

NAME = ft_ssl

LIBFT_DIR = ./libft/

LIBFT_NAME = ft

COMPIL_LIB = -L$(LIBFT_DIR) -l$(LIBFT_NAME)

SRCS_DIR = srcs/

INCS_DIR = includes/

SRCS_LIST = main \
			md5 \
			md5_fct \
			sha256 \
			sha256_224 \
			sha512 \
			sha512_384 \
			whirlpool \
			whirlpool_fct \
			padding \
			utils \
			sha_makeword \
			interactive \
			display_help \
			parse \
			parse_type \
			print_digest \
			errors \
			init \

INCS =	ft_ssl \
		proto \
		libinc \

SRCS =  $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_LIST)))

OBJECT = ${SRCS:.c=.o}

HEADERS =	$(addprefix $(INCS_DIR), $(addsuffix .h, $(INCS)))

all : $(NAME)

.c.o: 
	${CC} $(FLAGS) -c -I $(INCS_DIR) -I $(LIBFT_DIR) $< -o ${<:.c=.o}

$(NAME): $(OBJECT) libft $(HEADERS) Makefile
	$(CC) -o $(NAME) $(OBJECT) $(COMPIL_LIB) $(FLAGS) 

libft: break_implicit_rule
	@make -C $(LIBFT_DIR)

break_implicit_rule:

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

ffclean: fclean
	@make -C $(LIBFT_DIR) fclean

re : fclean all

rre: ffclean all

.PHONY: re clean fclean
