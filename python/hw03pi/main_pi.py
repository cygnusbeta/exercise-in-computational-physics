import math
import random
from collections import defaultdict


class Rnd_minus_1_to_1():
    def __init__(self):
        rnd = random.random()
        self.num = 2 * rnd - 1


def main_pi():
    n = 10 ** 4
    count = 0
    for i in range(n):
        x = Rnd_minus_1_to_1().num
        y = Rnd_minus_1_to_1().num
        r = math.sqrt(pow(x, 2) + pow(y, 2))
        if r <= 1:
            count += 1

    p = count / n
    q = 1 - p

    print('pi = {0:.3f} ± {1:.3f} (4 * {2} / {3})'.format(4 * p, 1.96 * 4 * math.sqrt(p * q / n), count, n)) # 誤差は 96% 信頼区間で算出した

if __name__ == '__main__':
    main_pi()
