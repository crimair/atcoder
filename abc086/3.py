import math


#a, b = map(int, input().split())
def test(a, b):
a, b = map(int, input().split())
c = int(str(a) + str(b))

f = 0
for i in range(1, 318):
    d = i * i
    if c == d:
        f = 1
        break
if f:
    print('Yes')
else:
    print('No')

    return f


for b in range(1, 101):
    for a in range(1, 101):
        f = test(a, b)
        c = int(str(a) + str(b))
        x = math.sqrt(c)
        xx = x - int(x)
        if xx == 0.0:
            if f == 0:
                print('err 0:', a, b)
                exit()
        else:
            if f == 1:
                print('err 1:', a, b)
                exit()
