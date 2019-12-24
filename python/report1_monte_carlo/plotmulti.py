# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np
import csv

def loop(d: int):
    data = []
    with open("../../cpp/out/r2_plot_{}d.csv".format(d)) as f:
        rows = csv.reader(f, quoting=csv.QUOTE_NONNUMERIC)
        for row in rows:
            data.append(row)

    # print(data)
    n = [row[0] for row in data]
    v = [row[1] for row in data]
    error = [row[2] for row in data]
    v_plus_error = [e + error[i] for i, e in enumerate(v)]
    v_minus_error = [e - error[i] for i, e in enumerate(v)]

    plt.plot(n, v, 'b', linestyle='solid')
    plt.plot(n, v_plus_error, 'b', linestyle='solid')
    plt.plot(n, v_minus_error, 'b', linestyle='solid')

    plt.axes().set_ylim(ymin=-max(v)*0.1, ymax=max(v_plus_error)*1.1)
    # plt.axes().set_aspect('equal', 'datalim')
    plt.grid(True, which="both", axis='both', ls="--", color="g")
    plt.xlabel('n')
    plt.ylabel('v')
    plt.savefig('r2plot{}d.eps'.format(d))
    plt.savefig('r2plot{}d.png'.format(d))
    plt.show()


def main():
    for d in range(2, 21):
        loop(d)


if __name__ == "__main__":
    main()
