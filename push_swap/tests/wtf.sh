#!/bin/python

from itertools import permutations

numbers = [1, 2, 3, 4, 5]
letters = ['a', 'b', 'c', 'd', 'e']

for idx, perm in enumerate(permutations(numbers), start=1):
    print(f"{idx}. {' < '.join(map(str, perm))}")
    print(f"   {' < '.join(letters[i-1] for i in perm)}\n")




