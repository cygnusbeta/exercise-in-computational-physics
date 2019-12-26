# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np
import csv

from matplotlib import ticker


def main():
    data = []
    with open('../../cpp/out/v_s_plot.csv') as f:
        rows = csv.reader(f, quoting=csv.QUOTE_NONNUMERIC)
        for row in rows:
            data.append(row)

    # print(data)
    d = [row[0] for row in data]
    v = [row[1] for row in data]
    error = [row[2] for row in data]

    # v_plus_error = [e + error[i] for i, e in enumerate(v)]
    # v_minus_error = [e - error[i] for i, e in enumerate(v)]

    # plt.plot('o')
    # plt.axes(yerr=error).errorbar()
    # plt.plot(n, v_plus_error, 'b', linestyle='solid')
    # plt.plot(n, v_minus_error, 'b', linestyle='solid')
    plt.errorbar(d, v, yerr=error, fmt='--o', ecolor='g')


    # plt.axes().set_ylim(ymin=-max(v)*0.1, ymax=max(v_plus_error)*1.1)
    # plt.axes().set_ylim(ymin=-0.1*v_theory[0], ymax=2.1*v_theory[0])
    plt.axes().set_xticks(np.arange(2, 21, step=1))
    # plt.xscale('log')
    # plt.yscale('log')
    plt.grid(True, which="both", axis='both', ls="--", color="grey")
    plt.xlabel('d')
    plt.ylabel('v ± 1.96 σ')
    plt.title('n = 10 ** 8')
    plt.savefig('out/v_s_plot.eps')
    plt.savefig('out/v_s_plot.png')
    plt.show()


if __name__ == "__main__":
    main()
