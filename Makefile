CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
NAME = push_swap
BONUS = checker
obj = ${SRC:.c=.o}
b_obj = ${SRC_BONUS:.c=.o}
SRC = src/push_swap.c src/moves_a.c src/moves_b.c src/fixat_moves.c src/algorithme.c src/managing_stack.c \
		src/utils.c src/parssing.c

all	  : ${NAME}

${NAME}: ${obj}
	@$(MAKE) -C libft
	@$(MAKE) bonus -C libft
	${CC} ${CFLAGS} ${obj} libft/libft.a  -o ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

bonus	  : ${BONUS}

${BONUS} : ${b_obj}
	@$(MAKE) -C libft
	@$(MAKE) bonus -C libft
	${CC} ${CFLAGS} ${b_obj} libft/libft.a  -o ${BONUS}

clean :
	@$(MAKE) clean -C libft
	@rm -fr ${obj}
	@rm -fr ${b_obj}

fclean : clean
	@$(MAKE) fclean -C libft
	@rm -fr ${NAME}
	@rm -fr ${BONUS}

re : fclean all
rebonus : fclean bonus
.SECONDARY : ${obj} ${b_obj}
