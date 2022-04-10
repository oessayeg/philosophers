BONUS_NAME = philo_bonus

BONUS_SRCS = $(addprefix ../philo_bonus/, error_functions_bonus.c main_philo_bonus.c \
	utils_bonus.c init_bonus.c process_routine_bonus.c process_waiting_bonus.c)

FL = -Wall -Wextra -Werror

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_SRCS)
	@cc $(Fl) $(BONUS_SRCS) -o $(BONUS_NAME)
	@printf "\033[33;5mThe executable 'philo_bonus' is ready !\n\033[0m"

clean : 
	@rm -f philo_bonus
	@printf "\033[31;5mThe executable is removed !\n\033[0m"

fclean : clean

re : fclean bonus

.PHONY : all clean fclean re
