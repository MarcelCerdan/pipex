.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	libft.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

# ---- Files ---- #

HEAD		=	libft.h

SRCS_MAIN	=	main.c

SRCS		=	ft_isalpha.c					ft_isdigit.c	\
				ft_isalnum.c					ft_isascii.c	\
				ft_isprint.c					ft_strlen.c		\
				ft_memset.c						ft_bzero.c		\
				ft_memcpy.c						ft_strlcpy.c	\
				ft_strlcat.c					ft_toupper.c	\
				ft_tolower.c					ft_strchr.c		\
				ft_strrchr.c					ft_strncmp.c	\
				ft_memchr.c						ft_memcmp.c		\
				ft_memmove.c					ft_strnstr.c	\
				ft_atoi.c						ft_strdup.c		\
				ft_substr.c						ft_strjoin.c	\
				ft_strtrim.c					ft_split.c		\
				ft_itoa.c						ft_strmapi.c	\
				ft_striteri.c					ft_putchar_fd.c	\
				ft_putstr_fd.c					ft_putendl_fd.c	\
				ft_putnbr_fd.c					ft_calloc.c		\
				ft_lstnew_bonus.c				ft_lstadd_front_bonus.c	\
				ft_lstsize_bonus.c				ft_lstlast_bonus.c 		\
				ft_lstadd_back_bonus.c			ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c				ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c				ft_itoa_printf.c		\
				ft_print_add.c					ft_print_un.c			\
				ft_printf_utils.c				ft_printf.c				\

OBJS		=	${SRCS:%.c=${DIR_OBJS}%.o}

OBJS_MAIN	=	${SRCS_MAIN:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
AR		=	ar rc

# ********* RULES ******** #

all			:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${HEAD}
					${AR} ${NAME} ${OBJS}

debug			:	${OBJS} ${OBJS_MAIN} Makefile ${HEAD}
					${CC} -g ${CFLAGS} -I . ${OBJS} ${OBJS_MAIN} -o debug

main			:	${OBJS} ${OBJS_BONUS} ${OBJS_OUTPUT} Makefile ${HEAD}
					${CC} ${CFLAGS} -I . ${OBJS} ${OBJS_MAIN} -o main

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${OBJS_MAIN}	:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	%.c ${HEAD} Makefile
					${CC} ${CFLAGS} -I . -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}

clean_main		:	clean
					${RM} main

clean_debug		:	clean
					${RM} debug

fclean			:	clean_main clean_debug
					${RM} ${NAME}

re				:	fclean all
