#!/usr/bin/env python
# -*- coding: utf-8 -*-
from pip._vendor.msgpack.fallback import xrange


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


def remove_duplicate(s_array):
    result = []
    for s in s_array:
        l = list(s)
        duplicate = False
        for c in l:
            if l.count(c) > 1:
                duplicate = True
                break
        if not duplicate:
            result.append(s)
    return result


def remove_line_duplicate(s_array, n):
    init_array = get_list_arranged(n)
    result = []
    for s in s_array:
        l = list(s)
        duplicate = False
        for i, c in enumerate(l):
            if c == str(i):
                duplicate = True
                break
        if not duplicate:
            result.append(s)
    return result
