.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	pipex

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	= 	srcs/

DIR_HEAD	=	incl/

# ---- Files ---- #

HEAD		=	pipex.h

SRCS		=	pipex.c		child.c		\
				error.c		ft_strlen.c	\
				ft_split.c

# ---- Paths ---- #

SRCS_PATH 	=	$(addprefix $(SRCS), $(SRCS_DIR))
OBJS		=	${SRCS_PATH:%.c=${DIR_OBJS}%.o}

HEAD_PATH 	=	$(addprefix $(HEAD), $(HEAD_DIR))

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

%.o			: 	%.c $(HEAD_PATH) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

all			:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS}
					${CC} ${CFLAGS} ${OBJS} -o ${NAME}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	%.c ${HEAD} Makefile
					${CC} ${CFLAGS} -I . -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

re				:	fclean all