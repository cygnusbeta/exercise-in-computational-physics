# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np
import csv

def main():
    data = []
    with open("../../cpp/out/x_y_plot_2d.csv") as f:
        rows = csv.reader(f, quoting=csv.QUOTE_NONNUMERIC)
        for row in rows:
            data.append(row)

    # print(data)
    x = [row[0] for row in data]
    y = [row[1] for row in data]
    plt.plot(x, y, 'b+', markersize=0.1)

    theta = np.linspace(0, np.pi / 2, 100)
    r = np.sqrt(1.0)
    circle_x = r * np.cos(theta)
    circle_y = r * np.sin(theta)
    plt.plot(circle_x, circle_y, 'black')

    plt.axes().set_aspect('equal', 'datalim')
    plt.grid(True, which="both", axis='both', ls="--", color="g")
    plt.xlabel('x')
    plt.ylabel('y')
    plt.savefig('out/plot2d.pdf')
    plt.savefig('out/plot2d.png')
    plt.show()


if __name__ == "__main__":
    main()
