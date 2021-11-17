#!/usr/bin/env python
input_n = 0

msg = """\
1 8 6
2 9 7
0 7 7
"""

msg = """\
0 8 8
0 8 8
0 8 8
"""

msg = """\
2 2 2
2 1 2
2 2 2
"""

msg = """\
1 0 1
2 1 2
1 0 1
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
    """
    0 0 0 0 0
    1 1 1 0 0
    0 0 0 0 0
    0 0 1 1 1
    0 0 0 0 0
    """
    # can goal?
    p = [0, 0]
    for i in range(h + w - 2):
        m


if __name__ == '__main__':
    main()
