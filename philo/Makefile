NAME = philo

SRCS = $(addprefix ../philo/, main_philo.c error_functions.c init_structures.c \
	utils.c thread_routine.c watcher.c utils_prime.c)

FL = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)
	@cc $(Fl) $(SRCS) -o $(NAME) -fsanitize=thread
	@printf "\033[33;5mThe executable 'philo' is ready !\n\033[0m"

clean : 
	@rm -f philo
	@printf "\033[31;5mThe executable is removed !\n\033[0m"

fclean : clean

re : fclean all

.PHONY : all clean fclean re
