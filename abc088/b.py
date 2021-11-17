#!/usr/bin/env python
input_n = 0

msg = """\
2018
218
"""

msg = """\
2763
0
"""

msg = """\
4
20 18 2 18
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
    n = int(input())
    c = list(map(int, input().split()))
    c.sort()

    a = 0
    b = 0
    for i in range(n):
        cn = c[n - i - 1]
        if i % 2 == 0:
            a += cn
        else:
            b += cn

    print(a - b)


if __name__ == '__main__':
    main()
