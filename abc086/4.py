input_n = 0

msg = """\
2
3 1 2
6 1 1
"""
msg = """\
2
5 1 1
100 1 1
"""
msg = """\
1
2 100 100
"""


def input():
    global input_n
    s = msg.split('\n')[input_n]
    input_n += 1
    return s


###################################33
## main code
###################################33


def travel(n, point):
    t = 0
    x = 0
    y = 0
    for i in range(n):
        t0, x0, y0 = point[i]
        stept = t0 - t
        stepd = abs(x0 - x) + abs(y0 - y)
        if stept < stepd:
            return False
        elif stept > stepd and ((stept - stepd) % 2 == 1):
            return False
        t = t0
        x = x0
        y = y0

    return True


def main():
    n = int(input())
    point = []
    for i in range(n):
        t, x, y = map(int, input().split())
        point.append([t, x, y])

    ret = travel(n, point)

    if ret:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()
