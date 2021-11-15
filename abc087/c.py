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
3 2 2 4 1
1 2 2 2 1
"""

msg = """\
4
1 1 1 1
1 1 1 1
"""

msg = """\
7
3 3 4 5 4 5 3
5 3 4 4 2 3 2
"""

msg = """\
1
2
3
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
class acc1d:
    def __init__(self, n):
        self.d = [0] * (n + 1)
        self.n = n

    def add(self, x, v):
        self.d[x + 1] += v
        pass

    def build(self):
        for i in range(self.n):
            self.d[i + 1] += self.d[i]
        pass

    def get(self, s, e):
        return self.d[e + 1] - self.d[s]


def candies(N, A):
    """
    0 1 2 3
    0 1 2 3
    """
    ans = 0
    for i0 in range(0, N):
        an = A[0].get(0, i0)
        bn = A[1].get(i0, N - 1)
        #print(i0, an, bn)
        ans = max(ans, an + bn)
    return ans


def main():
    n = int(input())
    a = []
    a.append(acc1d(n))
    a.append(acc1d(n))
    d = list(map(int, input().split()))
    for i in range(n):
        a[0].add(i, d[i])
    d = list(map(int, input().split()))
    for i in range(n):
        a[1].add(i, d[i])

    a[0].build()
    a[1].build()

    ret = candies(n, a)

    print(ret)


if __name__ == '__main__':
    main()
