#!/usr/bin/env python

import threading

class MyThread(threading.Thread):

    # def __init__(self):
    #     super(MyThread, self).__init__()

    def run(self):
        print("Running")


my_thread = MyThread()
my_thread.start()