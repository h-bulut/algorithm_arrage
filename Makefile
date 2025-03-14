NAME		= push_swap
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f
 
SRCS		=	steps/push.c \
				steps/reverse_rotate.c\
				steps/rotate.c\
				steps/swap.c\
				main.c\
				check_arg.c\
				utils_a.c\
				utils_b.c\
				utils_limits.c\
				utils_list_tools.c\
				utils_order.c\
				utils_tools.c\

OBJS		=	$(SRCS:.c=.o)

all			: $(NAME)

$(NAME) 	: $(OBJS)
		@echo "completed... continue!"
		@$(MAKE) -C ./libft all --silent
		@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) 

%.o			: %.c 
		@$(CC) $(CFLAGS) -c $< -o $@ 

clean		: 
		@$(MAKE) -C ./libft clean --silent
		@$(RM) $(OBJS) 

fclean 		: 
		@$(MAKE) -C ./libft fclean --silent
		@$(RM) $(OBJS) 
		@$(RM) $(NAME) 

re			: fclean all

.PHONY		: all clean fclean re 


		






