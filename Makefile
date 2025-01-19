NAME		= push_swap
LIBFT		= ./libraries/libft/libft.a

LIBC		= ar rcs
CC			= gcc
RM			= rm -f

FLAGS		= -Wall -Wextra -Werror -Iinc

SRCS 		= ./src/push_swap.c \

OBJS 		= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all :		$(LIBFT) $(NAME)

$(NAME) :	${OBJS} ${LIBFT} 
			@echo "Building push_swap..."
			@${CC} ${OBJS} ${LIBFT} $(FLAGS) -o ${NAME}

$(LIBFT) :
			@echo "Building libft..."
			@make -C libraries/libft > /dev/null 2>&1

clean:
			@echo "Cleaning..."
			@rm -f $(OBJS)
			@make clean -C libraries/libft > /dev/null 2>&1

fclean:		clean
			@echo "Cleaning all..."
			@rm -f $(NAME)
			@make fclean -C libraries/libft > /dev/null 2>&1

re: 		fclean all

.PHONY : all clean fclean re
