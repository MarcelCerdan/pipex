.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	pipex

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	= 	srcs/

DIR_BONUS	=	src_bonus/

DIR_HEAD 	=	incl/

DIR_LIBFT	=	libft

# ---- Files ---- #

HEAD_LST	=	pipex.h libft.h

HEAD_BONUS_LST	=	pipex_bonus.h libft.h

SRCS_LST 	= 	pipex.c		child.c	\
				error.c

BONUS_LST	=	pipex_bonus.c	child_bonus.c \
				error_bonus.c

OBJS_LST	=	${SRCS_LST:%.c=%.o}

OBJS_BONUS_LST	=	${BONUS_LST:%.c=%.o}

HEAD 		= 	$(addprefix $(DIR_HEAD), $(HEAD_LST))

HEAD_BONUS	=	$(addprefix $(DIR_HEAD), $(HEAD_BONUS_LST))

SRCS 		= 	$(addprefix $(DIR_SRCS), $(SRCS_LST))

BONUS		=	$(addprefix $(DIR_BONUS), $(BONUS_LST))

OBJS 		= 	$(addprefix $(DIR_OBJS), $(OBJS_LST))

OBJS_BONUS	=	$(addprefix $(DIR_OBJS), $(OBJS_BONUS_LST))

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all			:	libft.a ${NAME}

libft.a		:
				make -j -C ${DIR_LIBFT}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${HEAD}
					${CC} ${CFLAGS} -I $(DIR_HEAD) -L libft/ -lft ${OBJS} -o ${NAME}

bonus			:	${OBJS_BONUS} Makefile ${BONUS_HEAD} libft.a
					${CC} ${CFLAGS} -I $(DIR_HEAD) -L libft/ -lft ${OBJS_BONUS} -o $@

# ---- Compiled Rules ---- #


$(DIR_OBJS)%.o	:	$(DIR_SRCS)%.c ${HEAD} Makefile | $(DIR_OBJS)
					${CC} ${CFLAGS} -I $(DIR_HEAD) -c $< -o $@

$(DIR_OBJS)%.o	:	$(DIR_BONUS)%.c ${BONUS_HEAD} Makefile | $(DIR_OBJS)
					${CC} ${CFLAGS} -I $(DIR_HEAD) -c $< -o $@ 

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}


# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS} 

fclean			:	clean
					make fclean -C ${DIR_LIBFT}
					${RM} ${NAME} bonus

re				:	fclean
					$(MAKE) all
