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
    m = {i: [] for i in range(3)}

    for i in range(3):
        m[i] = list(map(int, input().split()))
    """
    a1 + b1, a2 + b1, a3 + b1
    a1 + b2, a2 + b2, a3 + b2
    a1 + b3, a2 + b3, a3 + b3
    """

    for j in range(3):
        for i in range(3):
            i0 = i
            j0 = j
            i1 = (i + 1) % 3
            j1 = (j + 1) % 3
            t = m[i0][j0] - m[i0][j1] - m[i1][j0] + m[i1][j1]
            if t != 0:
                print('No')
                return

    print('Yes')
    return


if __name__ == '__main__':
    main()
