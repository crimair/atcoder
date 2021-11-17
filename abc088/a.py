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
37
514
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


def infcoins(N, A):

    rem = N % 500
    if rem <= A:
        return True
    else:
        return False


def main():
    n = int(input())
    a = int(input())

    ret = infcoins(n, a)

    if ret:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()
