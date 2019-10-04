import random
from collections import defaultdict


def rnd_0_or_1():
    return random.randint(0, 1)


def main_random_walk_2d():
    n = 10
    res_array = []
    count_dict = defaultdict(int)
    for i in range(10):
        count = 0
        for j in range(n):
            num_rnd = rnd_0_or_1()
            count += num_rnd
        count_dict[count] += 1
        res_array.append(str(count))
    res = ' '.join(res_array)

    print(res)
    print()
    sum = 0
    for i in range(0, n + 1):
        print('おもて {0} 回: {1} 回'.format(
            '0' + str(i) if len(str(i)) == 1 else str(i),
            '0' + str(count_dict[i]) if len(str(count_dict[i])) == 1 else str(count_dict[i]),

        ))
        sum += count_dict[i]
    print('　　　 合計　: {} 回'.format(sum))


if __name__ == '__main__':
    main_random_walk_2d()
