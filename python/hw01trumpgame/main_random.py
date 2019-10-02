#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
import random

from hw01trumpgame.util import base_10_to_n, fill_to_n_digit, \
    is_line_duplicate, is_duplicate, is_line_duplicate_hex


class CalcRandom:
    def __init__(self, n: int):
        self.n = n

        c_array = []
        for i in range(self.n):
            while len(c_array) < self.n:
                c_num = random.randint(0, self.n - 1)
                c_num_hex = hex(c_num)
                c = str(c_num_hex)[2:]
                if c not in c_array:
                    c_array.append(c)
        self.num = ''.join(c_array)
        # while True:
        #     num_base10 = random.randint(0, self.n ** self.n - 1)
        #     # print(num_base10)
        #     self.num = base_10_to_n(num_base10, self.n)
        #     self.num = fill_to_n_digit(self.num, self.n)
        #     if is_duplicate(self.num):
        #         continue
        #     break
        # # print(self.num)


    def isDuplicate(self):
        return is_line_duplicate_hex(self.num)


def main_random():
    repeat_min_n = 1
    repeat_max_n = 13
    repeat = 10 ** 5
    count_not_duplicate_array = []
    for n in range(repeat_min_n, repeat_max_n + 1):
        # print(n)
        count_not_duplicate = 0
        for j in range(repeat):
            rnd = CalcRandom(n)
            duplicate = rnd.isDuplicate()
            if not duplicate:
                count_not_duplicate += 1
            if j % 100 == 0:
                print('{0} {1}'.format(rnd.num, 'duplicate' if duplicate else ''))
        count_not_duplicate_array.append(count_not_duplicate)
        print('P({0}) = {1}/{2}'.format(n, count_not_duplicate, repeat))
        print('     = {}'.format(count_not_duplicate / repeat))
        print()
    print('--- Result ---')
    print()
    for n in range(repeat_min_n, repeat_max_n + 1):
        print('P({0}) = {1}/{2}'.format(n, count_not_duplicate_array[n - repeat_min_n], repeat))
        print('     = {}'.format(count_not_duplicate_array[n - repeat_min_n] / repeat))
        print()

if __name__ == '__main__':
    main_random()
