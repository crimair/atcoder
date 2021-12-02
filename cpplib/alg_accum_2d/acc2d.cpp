#include <bits/stdc++.h>
using namespace std;

/**************************************************************/
template <int ih, int iw, typename T = int>
struct acc2d {
 public:
  const int h = ih;
  const int w = iw;
  T array[ih + 1][iw + 1] = {};

  void add(int y, int x, T v = 1) {
    array[y + 1][x + 1] += v;
  }

  void build() {
    for (int j = 0; j < h; j++) {
      for (int i = 0; i < w; i++) {
        array[j + 1][i + 1] += array[j + 1][i] + array[j][i + 1] - array[j][i];
      }
    }
  }

  T set(int y, int x, T v) {
    array[y + 1][x + 1] = v;
  }

  T set(int sy, int sx, int ey, int ex, T *v) {
    T *vv = v;
    T *vvv;
    for (int j = sy; j <= ey; j++) {
      vvv = vv;
      vv += (w + 1);
      for (int i = sx; i <= ex; i++) {
        array[j + 1][i + 1] = *(vvv++);
      }
    }
  }

  T get(int y, int x) {
    return array[y + 1][x + 1];
  }

  T get(int sy, int sx, int ey, int ex) {
    return array[ey][ex] - array[ey][sx] - array[sy][ex] + array[sy][sx];
  }
};

int main() {
  acc2d<10, 10> a;
  cout << a.get(0, 0) << endl;
}
