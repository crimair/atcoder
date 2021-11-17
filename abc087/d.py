input_n = 0

msg = """\
100000 0
8 7 100
7 9 100
9 8 100
"""

msg = """\
4 3
2 1 1
2 3 5
3 4 2
"""

msg = """\
3 3
1 2 1
2 3 1
1 3 2
"""

msg = """\
10 3
8 7 100
7 9 100
9 8 100
"""

msg = """\
100000 0
"""

msg = """\
8 7
1 2 2
1 3 3
1 4 5
2 4 3
2 3 1
3 8 5
4 8 3
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

# def people_check(N, infol):
#     nmax = 10**11
#     info = [nmax] * (N + 1)
#     check = [False] * (N + 1)
#     for l0 in range(1, N + 1):
#         #print(infol[l0])
#         for x0 in (infol[l0]):
#             p, d = x0
#             #if check[l0] == False:
#             if info[l0] >= nmax:
#                 check[l0] = True
#                 info[l0] = 0
#                 info[p] = d + info[l0]
#             else:
#                 #if check[p] == False:
#                 if info[p] >= nmax:
#                     check[p] = True
#                     info[p] = d + info[l0]
#                 else:
#                     temp = d + info[l0]
#                     if info[p] != temp:
#                         return False

#     return True


def people_check(N, infol):
    info = [0] * (N + 1)
    check = [False] * (N + 1)
    for l0 in range(1, N + 1):
        recheck = []
        if check[l0] == False:
            recheck.append(l0)
            check[l0] = True
            info[l0] = 0

            while len(recheck) > 0:
                sel = recheck.pop()
                for p, d in infol[sel]:
                    if check[p] == False:
                        check[p] = True
                        info[p] = d + info[sel]
                        recheck.append(p)
                    else:
                        temp = d + info[sel]
                        if info[p] != temp:
                            return False

    return True


def main():
    n, m = map(int, input().split())
    infol = {i: [] for i in range(n + 1)}

    for i in range(m):
        l, r, d = map(int, input().split())
        infol[l].append([r, d])
        infol[r].append([l, -d])
        #print(l, r, d, infol)

    ret = people_check(n, infol)

    if ret:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()
