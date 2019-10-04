#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pip._vendor.msgpack.fallback import xrange


def gen_num_array_hex(n):
    c_array = dict()
    progress = 0
    i = 0
    while i < progress:
        # c_num = random.randint(0, n - 1)
        c_num_hex = hex(c_num)
        c = str(c_num_hex)[2:]
        if c not in c_array:
            c_array.append(c)


def get_list_arranged(n):
    # fact = math.factorial(n) + 1
    base_10_array = list(xrange(n ** n))
    # print(base_10_array)
    base_n_array = [base_10_to_n(v, n) for v in base_10_array]
    # print(base_n_array)
    base_n_array_filled = [fill_to_n_digit(v, n) for v in base_n_array]
    return base_n_array_filled


def base_10_to_n(X, n):
    if X == 0:
        return '0'
    X_dumy = X
    out = ''
    while X_dumy > 0:
        out = str(X_dumy % n) + out
        X_dumy = int(X_dumy / n)
    return out


def fill_to_n_digit(s, n):
    while len(s) < n:
        s = '0' + s
    return s


def is_duplicate(s):
    l = list(s)
    duplicate = False
    for c in l:
        if l.count(c) > 1:
            duplicate = True
            break
    return duplicate


def remove_duplicate(s_array):
    result = []
    for s in s_array:
        duplicate = is_duplicate(s)
        if not duplicate:
            result.append(s)
    return result


def is_line_duplicate(s):
    l = list(s)
    duplicate = False
    for i, c in enumerate(l):
        if c == str(i):
            duplicate = True
            break
    return duplicate


def is_line_duplicate_hex(s):
    l = list(s)
    duplicate = False
    for i, c in enumerate(l):
        if c == str(hex(i))[2:]:
            duplicate = True
            break
    return duplicate



def remove_line_duplicate(s_array):
    result = []
    for s in s_array:
        duplicate = is_line_duplicate(s)
        if not duplicate:
            result.append(s)
    return result


def remove_line_duplicate_hex(s_array):
    result = []
    for s in s_array:
        duplicate = is_line_duplicate_hex(s)
        if not duplicate:
            result.append(s)
    return result