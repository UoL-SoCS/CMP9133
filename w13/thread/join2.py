#!/usr/bin/env python

import threading
import time

class MyThread(threading.Thread):

    def __init__(self):
        super(MyThread, self).__init__()

    def run(self):
        print("Running")
        time.sleep(5)

my_thread = MyThread()
my_thread.start()
my_thread.join()
print("Finished")