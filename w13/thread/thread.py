#!/usr/bin/env python

import threading

def my_function():
    print("Thread function")

if __name__ == "__main__":
    my_thread = threading.Thread(target=my_function)
    my_thread.start()