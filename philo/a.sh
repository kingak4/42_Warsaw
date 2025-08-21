#!/bin/bash

run_program(){
    for i in {1..100}
    do
        ./philo 5 800 200 200 7 | grep died
    done
    # for i in {1..10}
    # do
    #     ./philo 4 410 200 100 10 | grep "died"
    # done
}

run_program
