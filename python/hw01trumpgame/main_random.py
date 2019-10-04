#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
import random

from pygments.util import xrange

from hw01trumpgame.util import base_10_to_n, fill_to_n_digit, \
    is_line_duplicate, is_duplicate, is_line_duplicate_hex


class CalcRandom:
    def __init__(self, n: int, list_arranged: list):
        self.n = n

        c_array = random.sample(list_arranged, len(list_arranged))
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
    repeat_min_n = 13
    repeat_max_n = 13
    repeat = 10 ** 6
    count_not_duplicate_array = []
    for n in range(repeat_min_n, repeat_max_n + 1):
        # print(n)
        count_not_duplicate = 0
        list_arranged = [str(hex(num))[2:] for num in xrange(n)]
        for j in range(repeat):
            rnd = CalcRandom(n, list_arranged)
            duplicate = rnd.isDuplicate()
            if not duplicate:
                count_not_duplicate += 1
            if j % 10000\
                    == 0 and j:
                # print('{0} {1}'.format(rnd.num, 'duplicate' if duplicate else ''))
                print()
                print(
                    'P({0}) = {1}/{2}'.format(n, count_not_duplicate, j))
                print('     = {}'.format(count_not_duplicate / j))
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
