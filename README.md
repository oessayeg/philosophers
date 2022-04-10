# Philosophers

This is a project from the third circle of the 42 cursus. It introduces to two major problems that happen in operating systems which are :
- [Deadlock](https://www.geeksforgeeks.org/introduction-of-deadlock-in-operating-system/)
- [Starvation](https://en.wikipedia.org/wiki/Starvation_(computer_science))


## The problem 
   * There is n philosophers sitting around a table, there are as many forks as them and a bowl of spaghetti
   * Philosophers can be in 3 states : eating, sleeping or thinking state, each one can eat only if he has two forks.
   * Philosophers are threads (processes for the bonus part), forks are mutexes (semaphores for the bonus part).
   * Make a program that synchronizes the philosophers ,avoid deadlocks and starvation.
 
## The program's arguments  
   1. Number of philosophers
   2. Time to die (If a philosopher didn’t start eating time_to_die miliseconds since the beginning of their last meal they die)
   3. Time to eat (The time that they should spend eating (using forks))
   4. Time to sleep (The time that they should spend sleeping)
   5. (optional) Number of meals (If all philosophers ate n meals, the simulation stops)

## How to use
  * Enter the folder 'philo' (threads and mutexes) or philo_bonus (processes and semaphores)
  * Type make for the compilation process
  * Execute with the desired arguments

## Some examples of the execution
  * ./philo 5 800 200 200 or ./philo_bonus 5 800 200 200 (the simulation will never end)
  * ./philo 2 400 150 150 7 or ./philo_bonus 2 400 150 150 7 (the simulation will stop when all philosophers eat 7 times)
  * ./philo 4 310 200 100 or ./philo_bonus 4 310 200 100 (a philosopher will die)
