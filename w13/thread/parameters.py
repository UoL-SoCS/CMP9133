#!/usr/bin/env python

import threading


def my_function(number):
    print("Thread number " + str(number))


if __name__ == "__main__":
    my_thread = threading.Thread(target=my_function, args=(1))
    my_thread.start()