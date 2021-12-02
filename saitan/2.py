#!/usr/bin/env python
input_n = 0

msg = """\
3 6
0 3 1 4 1 5
9 2 6 5 3 5
3 9 7 9 3 2
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

import copy


# ダイクストラ法
class state:
    def __init__(self, y, x, cost) -> None:
        self.y = y
        self.x = x
        self.cost = cost

    # print
    def __repr__(self):
        return '(' + str(self.y) + ',' + str(self.x) + ')'

    # equal
    def __eq__(self, other):
        if not isinstance(other, state):
            return NotImplemented
        return (self.y == other.y and self.x == other.x)


def dijkstra(h, w, m, s, g):

    openlist = []
    closedlist = []
    pos = state(s[0], s[1], m[s[0]][s[1]])

    dx = (0, 1)
    dy = (1, 0)

    openlist.append(pos)

    while len(openlist) != 0:
        ## cost priority
        hq = 0
        hqcost = openlist[0].cost
        for i, hque in enumerate(openlist[1:]):
            if hqcost > hque.cost:
                hq = i + 1
                hqcost = hque.cost

        st = openlist.pop(hq)

        # goalしたとき
        if st.y == g[0] and st.x == g[1]:
            return st.cost

        # closedlistは、チェック済みの経路
        # その場所を通る場合の最短経路は、すでに探索済みのためスキップする
        if st in closedlist:
            continue

        # 探索済み経路として記載
        closedlist.append(st)

        # 4方向へ試しに移動してみる。
        for i in range(2):
            ny = st.y + dy[i]
            nx = st.x + dx[i]
            # 移動した先が範囲外だったら
            if not (0 <= nx and nx < w and 0 <= ny and ny < h):
                continue

            ncost = st.cost + m[ny][nx]

            openlist.append(state(ny, nx, ncost))

    return -1


def main():
    h, w = map(int, input().split())

    m = {i: [] for i in range(h)}

    for i in range(h):
        m[i] = list(map(int, input().split()))

    cost = dijkstra(h, w, m, (0, 0), (h - 1, w - 1))

    print(cost)


if __name__ == '__main__':
    main()
