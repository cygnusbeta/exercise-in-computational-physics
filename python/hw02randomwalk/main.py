import random


def rnd_plus_or_minus_1():
    return 1 if random.randint(0, 1) else -1


def main():
    for i in range(1, 10 + 1):
        res_array = []
        count = 0
        for j in range(i):
            num_rnd = rnd_plus_or_minus_1()
            count += num_rnd
            res_array.append('〇' if num_rnd == 1 else '×')
        res = ' '.join(res_array)
        i_str = '0' + str(i) if len(str(i)) == 1 else str(i)
        count_str = '+' + str(count) if count > 0 else ' ' + str(count) if count == 0 else str(count)
        print('n = {0}: {1} ({2})'.format(i_str, count_str, res))


if __name__ == '__main__':
    main()
