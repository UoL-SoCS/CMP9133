#!/usr/bin/env python

from multiprocessing import Process


def my_function(text):
    print("Hello,", text)


if __name__ == "__main__":
    p = Process(target=my_function, args=('World!',))
    p.start()
    p.join()