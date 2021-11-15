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

class acc2d():
    def __init__(self, w, h):
        self.w = w
        self.h = h
        self.array = [[0] * (w + 1) for _ in range(h + 1)]

    def add(self, w, h, v=1):
        self.array[h + 1][w + 1] += v

    """
    0  a[0] a[1] a[2] a[3] a[4] a[5]
    s0  s1   s2   s3   s4   s5   s6
    sums(a[3:6]) -> s6 - s3
    """

    def build(self):
        # for i in range(len( self.array )):
        #     print(self.array[len(self.array) - i - 1])
        for j in range(self.h):
            for i in range(self.w):
                self.array[j + 1][i + 1] += \
                    self.array[j + 1][i] \
                    + self.array[j][i+1] \
                    - self.array[j][i]
        # print("")
        # for i in range(len( self.array )):
        #     print(self.array[len(self.array) - i - 1])

    def get(self, sx, sy, ex, ey):
        return \
            self.array[ey][ex] \
            - self.array[ey][sx] \
            - self.array[sy][ex] \
            + self.array[sy][sx]


def checker(N, K, point, col):

    K2 = K * 2
    mb = acc2d(K2, K2)

    for n in range(N):
        x, y = point[n]
        c = col[n]
        x %= K2
        y += K if c == 1 else 0 #
        y %= K2
        mb.add(x, y)

    mb.build()

    res = 0
    for x in range(K):
        for y in range(K):
            bs = 0
            bs += mb.get(x, y, x + K, y + K)   # center 
            bs += mb.get(0, y + K, x, K2)      # top-left
            bs += mb.get(0, 0, x, y)           # bottom-left
            bs += mb.get(x + K, y + K, K2, K2) # top-right 
            bs += mb.get(x + K, 0, K2, y)      # bottom-right
            """
            bs = w b
                 b w

            N -bs = b w
                    w b
            """
            res = max(res, bs, N-bs)

    return res


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
