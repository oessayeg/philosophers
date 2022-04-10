# Philosophers

This is a project from the third circle of the 42 cursus. It introduces to two major problems that happen in operating systems which are :
- [Deadlock](https://www.geeksforgeeks.org/introduction-of-deadlock-in-operating-system/)
- [Starvation](https://en.wikipedia.org/wiki/Starvation_(computer_science))


## The problem 
   * There is n philosophers sitting around a table
   * There are as many forks as philosophers and a bowl of spaghetti
   * Philosophers can be in 3 states : eating, sleeping or thinking state.
   * Each philosopher can eat only if he has two forks. 
   * Philosophers are threads (processes for the bonus part), forks are mutexes (semaphores for the bonus part).
   * Make a program that synchronizes the philosophers and make them avoid dying.
   * The program takes 5 arguments:
   
   1. Number of philosophers
    2. Time to die (If a philosopher didn’t start eating time_to_die miliseconds since the beginning of their last meal they die)
    3. Time to eat (The time that they should spend eating (using forks))
            4. Time to sleep (The time that they should spend sleeping)
            5. (optional) Number of meals (If all philosophers ate n meals, the simulation stops)


    
