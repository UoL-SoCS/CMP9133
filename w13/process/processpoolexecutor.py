#!/usr/bin/env python

from concurrent.futures import ProcessPoolExecutor

values = [2, 3, 4, 5]

def square(n):
   return n * n

if __name__ == "__main__":
   with ProcessPoolExecutor(max_workers = 3) as executor:
        print(executor.map(square, values))
      #   for result in results:
      #       print(result)