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
