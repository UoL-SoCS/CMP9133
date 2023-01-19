#!/usr/bin/env python

from time import sleep
from random import random
from threading import Thread
from threading import Barrier
 
# target function to prepare some work
def task(barrier, number):
    # generate a unique value
    value = random() * 10
    # block for a moment
    sleep(value)
    # report result
    print(f'Thread {number} done, got: {value}')
    # wait on all other threads to complete
    barrier.wait()


if __name__ == '__main__':
    # create a barrier
    barrier = Barrier(5 + 1)
    # create the worker threads
    for i in range(5):
        # start a new thread to perform some work
        worker = Thread(target=task, args=(barrier, i))
        worker.start()
    # wait for all threads to finish
    print('Main thread waiting on all results...')
    barrier.wait()
    # report once all threads are done
    print('All threads have their result')