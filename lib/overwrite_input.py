input_n = 0

msg = """\
6 2
1 2 B
2 1 W
2 2 B
1 0 B
0 6 W
4 5 W
"""

msg = """\
2 1000
0 0 B
0 1 W
"""

msg = """\
4 3
0 1 W
1 2 W
5 3 B
5 4 B
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
    n, k = map(int, input().split())
    point = []
    col = []
    for i in range(n):
        x, y, c = input().split()
        x = int(x)
        y = int(y)
        c = 0 if c == 'B' else 1
        point.append([x, y])
        col.append(c)

    ret = checker(n, k, point, col)

    print(ret)


if __name__ == '__main__':
    main()
