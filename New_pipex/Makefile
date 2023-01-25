NAME		=	pipex

HEADER		=	./includes/

LIBFT		=	libft/libft.a

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER) #-fsanitize=address

SRCS		=	mandatory/child.c \
				mandatory/erro.c\
				mandatory/free.c \
				mandatory/pipex.c\

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT)	:
				make -C ./libft

clean		:
				rm -rf $(OBJS)
				make clean -C ./libft

fclean		:	clean 
				$(MAKE) -C libft fclean
				$(RM) $(NAME)

re			:	fclean all