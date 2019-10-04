#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math

from hw01trumpgame.util import *


def main():
    for i in range(1, 13):
        calc(i)


def calc(n):
    # print('n = {}'.format(n))
    # list_not_duplicate = gen_num_array_hex(n)
    list_arranged = get_list_arranged(n)
    list_not_duplicate = remove_duplicate(list_arranged)
    # list_not_duplicate = gen_num_array(n)
    print(list_not_duplicate)
    result = remove_line_duplicate_hex(list_not_duplicate)
    # print(result)
    num = len(result)
    # print(num)
    print('P({0}) = {1}/{2}'.format(n, num, math.factorial(n)))
    print('     = {}'.format(num/math.factorial(n)))
    print()

if __name__ == '__main__':
    main()
