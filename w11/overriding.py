#!/usr/bin/env python

class Parent(object):
    def __init__(self):
        self.value = 10
    def get_value(self):
        return self.value

class Child(Parent):
    def get_value(self):
        return self.value * 2

parent = Parent()
print(parent.get_value()) #10

child = Child()
print(child.get_value()) #20
