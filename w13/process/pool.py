#!/usr/bin/env python

from multiprocessing import Pool


def square(n):
   return n * n


if __name__ == "__main__":
    with Pool(3) as p:
        print(p.map(square, [1, 2, 3]))