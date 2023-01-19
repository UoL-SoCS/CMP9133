#!/usr/bin/env python

from concurrent.futures import ThreadPoolExecutor

values = [2, 3, 4, 5]

def square(n):
   return n * n

if __name__ == "__main__":
   with ThreadPoolExecutor(max_workers = 3) as executor:
        results = executor.map(square, values)
        for result in results:
            print(result)