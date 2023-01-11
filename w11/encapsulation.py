#!/usr/bin/env python

class Person:
    def __init__(self, name, parent_name, age=0):
        self.name = name
        self._parent_name = parent_name
        self.__age = age
    
    def display(self):
        print("Display personal information:")
        print(self.name)
        print(self.__age)

    def get_age(self):
        print(self.__age)

    def set_age(self, age):
        self.__age = age

person = Person('Dev', 'DevOps', 32)

print(person.name)
print(person._parent_name)
print(person.__age)

person.display()