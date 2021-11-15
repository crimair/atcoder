input_n = 0

msg = """\
30
40
50
6000
"""

msg = """\
2
2
2
100
"""

msg = """\
5
1
0
150
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


def coins(A, B, C, X):

    n = 0
    cmax = 50 * C
    for a in range(A + 1):
        y0 = 500 * a
        x0 = X - y0
        for b in range(B + 1):
            y1 = 100 * b
            x1 = x0 - y1
            if x1 >= 0 and cmax >= x1:
                n += 1
                #print(a, b, x1)

    return n


def main():
    a = int(input())
    b = int(input())
    c = int(input())
    x = int(input())

    ret = coins(a, b, c, x)

    print(ret)


if __name__ == '__main__':
    main()
