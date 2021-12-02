#include <bits/stdc++.h>

using namespace std;

// string msg = R"(
// 3 3 2
// 1 4 3
// 2 5 7
// 8 9 6
// 1
// 4 8
// )";

// string msg = R"(
// 4 2 3
// 3 7
// 1 4
// 5 2
// 6 8
// 2
// 2 2
// 2 2
// )";

string msg = R"(
5 5 4
13 25 7 15 17
16 22 20 2 9
14 11 12 1 19
10 6 23 8 18
3 21 5 24 4
3
13 13
2 10
13 13
)";

void localout() {
  ofstream out("input.txt");
  out << msg.substr(1, -1);
}

/**************************************************************/

#include <bits/stdc++.h>

using namespace std;

template <class T = int>
inline vector<T> V(int size = 0) {
  return vector<T>(size);
}
template <class T = int>
inline vector<T> V(int size, T init) {
  return vector<T>(size, init);
}
template <class T = int>
inline vector<vector<T>> VV(int ysize, int xsize) {
  return vector<vector<T>>(ysize, vector<T>(xsize));
}
template <class T = int>
inline vector<vector<T>> VV(int ysize, int xsize, T init) {
  return vector<vector<T>>(ysize, vector<T>(xsize, init));
}

typedef struct {
  int y;
  int x;
} p2;
typedef struct {
  int z;
  int y;
  int x;
} p3;

template <typename T = int>
struct pt2 {
  T y;
  T x;
};
template <typename T = int>
struct pt3 {
  T z;
  T y;
  T x;
};

// macro
#define CIN(a) cin >> a
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define CIN4(a, b, c, d) cin >> a >> b >> c >> d
#define COUT(a) cout << (a)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define VIN(v) \
  for (auto& _a : v) cin >> _a
#define VIN2(v)      \
  for (auto& _a : v) \
    for (auto& _b : _a) cin >> _b
#define SORT(v) sort(v.begin(), v.end())
#define REVERSE(v) reverse(v.begin(), v.end())

#define Yes(f) cout << (f) ? "Yes" : "No" << endl
#define YES(f) cout << (f) ? "YES" : "NO" << endl

// debug macro
template <class TupType, size_t... I>
void print_tuple(const TupType& _tup, index_sequence<I...>) {
  (..., (cout << (I == 0 ? "" : ", ") << get<I>(_tup)));
  cout << endl;
}

template <class... T>
void print_tuple(const tuple<T...>& _tup) {
  print_tuple(_tup, make_index_sequence<sizeof...(T)>());
}
#define DOUT(...) print_tuple(make_tuple(__VA_ARGS__))

#define VOUT(v)                         \
  for (auto& _a : v) cout << _a << ' '; \
  cout << endl
#define VOUT2(v)                           \
  for (auto& _a : v)                       \
    for (auto& _b : _a) cout << _b << ' '; \
  cout << endl

/**************************************************************/

int main() {
#ifdef LOCAL_DEBUG
  localout();
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
#else
  ios::sync_with_stdio(false);
#endif
  int h, w, d;
  CIN3(h, w, d);

  auto point = V<p2>(h * w + 1);

  REP(j, h) REP(i, w) {
    int l;
    CIN(l);
    point[l].y = j;
    point[l].x = i;
  }

  auto cost = V<int>(h * w + 1, 0);

  FOR(i, 1, d + 1) {
    int pre_y = point[i].y;
    int pre_x = point[i].x;
    cost[i] = 0;
    FOR(j, 1, int((h * w + d) / d)) {
      if ((i + j * d) > (h * w)) {
        break;
      }
      int y = point[i + j * d].y;
      int x = point[i + j * d].x;
      int t = abs(y - pre_y) + abs(x - pre_x);
      pre_y = y, pre_x = x;
      cost[i + d * j] = t + cost[i + (d * (j - 1))];
    }
  }

  int q;
  CIN(q);

  REP(i, q) {
    int L, R;
    CIN2(L, R);

    int power = cost[R] - cost[L];
    cout << power << endl;
  }

  return 0;
}
