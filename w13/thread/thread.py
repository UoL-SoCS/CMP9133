#!/usr/bin/env python

import threading
import time

def my_function():
    # print("Thread function")
    time.sleep(5)

if __name__ == "__main__":
    my_thread = threading.Thread(target=my_function)
    my_thread.start()