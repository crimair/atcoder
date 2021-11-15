a, b = map(int, input().split())
f = (a & 1) & (b & 1)
if f:
    print('Odd')
else:
    print('Even')
