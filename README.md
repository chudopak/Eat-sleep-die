# Dining philosophers problem
This is the simple representation of solving [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).<br/>
![philosophers image](https://adit.io/imgs/dining_philosophers/happy_and_sad.png)

## Usage
***Philosophers should avoid dying***
1. Run command below in your terminal;
```
git clone https://github.com/chudopak/Eat-sleep-die.git ; cd Eat-sleep-die
```
2. Do `make`;
3. Run tests:
```
./philo 5 800 200 200 5
./philo 10 1000 200 100
./philo 100 1000 100 100 10
```
To stop simulation type __CTRL__ + __c__ ( *Just in case* **:)** )
![philo](./philo.gif)

## Received arguments
Each program should have the same options: 
- number_of_philosophers;
- time_to_die;
- time_to_eat;
- time_to_sleep;
- number_of_times_each_philosopher_must_eat (optional);

## Algorithm
- think until the left fork is available, when it is, pick it up;
- think until the right fork is available, when it is, pick it up;
- when both forks are held, eat for a fixed amount of time;
- then, put the right fork down;
- then, put the left fork down;
- repeat.

***Deadlock*** does not happen because all philosophers take the left fork first then the right fork and the last philosopher takes the right fork and then the left.