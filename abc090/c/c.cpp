#include <bits/stdc++.h>

using namespace std;

string msg = R"(
314 1592
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
  int64_t n, m;
  CIN2(n, m);

  int64_t n1 = (n == 1) ? 1 : n - 2;
  int64_t m1 = (m == 1) ? 1 : m - 2;
  cout << n1 * m1 << endl;

  return 0;
}

// int X = 1;
// int Y = 5;
// auto r = VV<int>(Y + 2, X + 2, 0);
// FOR(j, 1, Y + 1) {
//   FOR(i, 1, X + 1) {
//     FOR(y, -1, 2) {
//       FOR(x, -1, 2) {
//         r[j + y][i + x] ^= 1;
//       }
//     }
//   }
// }
// REP(i, Y) {
//   VOUT(vector<int>(r[i + 1].begin() + 1, r[i + 1].end() - 1));
// }
