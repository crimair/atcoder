#!/usr/bin/env python
input_n = 0

msg = """\
2 5
0 1 2 3 4
5 6 7 8 9
"""


def input():
    global input_n
    s = msg.split('\n')[input_n]
    input_n += 1
    return s


import time


class stopwatch:
    def __init__(self):
        pass

    def start(self):
        self.start_time = time.time()

    def stop(self):
        self.stop_time = time.time()
        print(self.stop_time - self.start_time)


###################################33
## main code
###################################33


def main():
    h, w = map(int, input().split())

    m = {i: [] for i in range(h)}

    for i in range(h):
        m[i] = list(map(int, input().split()))

    up = [-1, 0]
    down = [1, 0]
    left = [0, -1]
    right = [0, 1]

    pos = [0, 0]

    cost = m[pos[0]][pos[1]]
    for step in (right, down, right, up, left):
        pos[0] += step[0]
        pos[1] += step[1]
        cost += m[pos[0]][pos[1]]

    print(cost)


if __name__ == '__main__':
    main()
