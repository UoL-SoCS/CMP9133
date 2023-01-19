#!/usr/bin/env python

import threading

def explicit(lock):
    lock.acquire()
    try:
        # do something​
        print("[Explicit]Lock acquired")
    finally:
        lock.release()

def implicit(lock):
    with lock:
        # do something        ​
        print("[Implicit]Lock acquired")


if __name__ == "__main__":
    lock = threading.Lock()
    thread_1 = threading.Thread(target= explicit, args=(lock,))
    thread_2 = threading.Thread(target= implicit, args=(lock,))
    thread_1.start()
    thread_2.start()