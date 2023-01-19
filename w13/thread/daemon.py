#!/usr/bin/env python

import threading
import time

def my_function():
    time.sleep(5)


if __name__ == "__main__":
    my_thread = threading.Thread(target=my_function, daemon=True)
    my_thread.start()