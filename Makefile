NAME = push_swap

NAME_BONUS = checker

SRCS = srcs/operations.c srcs/ft_atoi.c srcs/gest_pile.c srcs/check_arg.c srcs/utils.c

SRCS_MANDATORY = srcs/main_push_swap.c srcs/tri_a.c srcs/count_mouv.c srcs/set_piles.c \
				 srcs/pretri.c srcs/push_swap.c srcs/calcul_mediane.c

SRCS_BONUS = bonus/check_pile.c bonus/checker.c bonus/create_list_op.c \
			 bonus/do_op.c bonus/utils.c bonus/utils_2.c bonus/main_checker.c

INCLUDES = -I ./

INCLUDES_BONUS = -I ./bonus/

OBJS = ${SRCS:.c=.o}

OBJS_MANDATORY = ${SRCS_MANDATORY:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

CFLAGS = -g3

RM = rm -rf

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${OBJS_MANDATORY}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_MANDATORY} ${INCLUDES}

${NAME_BONUS}:	${OBJS} ${OBJS_BONUS}
				${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS} ${OBJS_BONUS} ${INCLUDES_BONUS}

all:		${NAME} ${NAME_BONUS}

bonus:		${NAME_BONUS}

clean:
			${RM} ${OBJS} ${OBJS_MANDATORY} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME} ${NAME_BONUS}

re:			fclean ${NAME}

.PHONY:		all clean fclean re bonus