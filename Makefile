.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	pipex

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	= 	srcs/

DIR_HEAD 	=	incl/

DIR_LIBFT	=	libft

# ---- Files ---- #

HEAD_LST	=	pipex.h libft.h

SRCS_LST 	= 	pipex.c		child.c	\
				error.c

OBJS_LST	=	${SRCS_LST:%.c=%.o}

HEAD 		= 	$(addprefix $(DIR_HEAD), $(HEAD_LST))

SRCS 		= 	$(addprefix $(DIR_SRCS), $(SRCS_LST))

OBJS 		= 	$(addprefix $(DIR_OBJS), $(OBJS_LST))

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all			:	libft.a ${NAME}

libft.a		:
				make -C ${DIR_LIBFT}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${HEAD}
					${CC} ${CFLAGS} -I $(DIR_HEAD) -L libft/ -lft ${OBJS} -o ${NAME}

debug			:	${OBJS} Makefile ${HEAD}
					${CC} -g ${CFLAGS} -I $(DIR_HEAD) -L libft/ -lft ${OBJS} -o $@

# ---- Compiled Rules ---- #


$(DIR_OBJS)%.o	:	$(DIR_SRCS)%.c ${HEAD} Makefile | $(DIR_OBJS)
					${CC} ${CFLAGS} -I $(DIR_HEAD) -c $< -o $@ 

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}


# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS} 

fclean			:	clean
					make fclean -C ${DIR_LIBFT}
					${RM} ${NAME}

re				:	fclean
					$(MAKE) all
