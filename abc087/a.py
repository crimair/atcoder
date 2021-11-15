input_n = 0

msg = """\
1234
150
100
"""

msg = """\
1000
108
108
"""

msg = """\
579
123
456
"""

msg = """\
7477
549
593
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


def buysweets(X, A, B):

    return (X - A) % B


def main():
    x = int(input())
    a = int(input())
    b = int(input())

    ret = buysweets(x, a, b)

    print(ret)


if __name__ == '__main__':
    main()
