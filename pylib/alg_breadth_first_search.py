#!/usr/bin/env python
input_n = 0

msg = """\
3 6
0 0 1 0 0 0
1 0 1 0 1 0
0 0 0 0 1 0
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


# 幅優先探索
# breadth first search
def bfs(h, w, m, s, g):

    openlist = []
    closedlist = []
    pos = s[:]

    dx = (0, -1, 0, 1)
    dy = (1, 0, -1, 0)

    openlist.append(pos[:])
    cost = 1

    while True:
        tmpque = []
        # openlistへは、1step進んだ時の位置情報がすべて入れられている。
        # 範囲外であったり、進めなくなった場合には次のopenlistへは記載されなくなる。
        while len(openlist) != 0:
            st = openlist.pop()

            # goalしたとき
            if st[0] == g[0] and st[1] == g[1]:
                return cost

            # 通れない場合
            if m[st[0]][st[1]] == 1:
                continue

            # closedlistは、チェック済みの経路
            # その場所を通る場合の最短経路は、すでに探索済みのためスキップする
            if st in closedlist:
                continue

            # 探索済み経路として記載
            closedlist.append(pos[:])

            # 4方向へ試しに移動してみる。
            for i in range(4):
                ny = st[0] + dy[i]
                nx = st[1] + dx[i]
                # 移動した先が範囲外だったら
                if not (0 <= nx and nx < w and 0 <= ny and ny < h):
                    continue

                # 範囲内なら次の探索経路の位置情報を記録する
                tmpque.append([ny, nx])

        # queをコピーする
        openlist = copy.deepcopy(tmpque)
        # cost = step数を1つ上げる
        cost += 1


def main():
    h, w = map(int, input().split())

    m = {i: [] for i in range(h)}

    for i in range(h):
        m[i] = list(map(int, input().split()))

    cost = bfs(h, w, m, (0, 0), (h - 1, w - 1))

    print(cost)


if __name__ == '__main__':
    main()
