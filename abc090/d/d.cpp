#include <bits/stdc++.h>

using namespace std;

string msg = R"(
1000000 0
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
void RR(int64_t n, int64_t k) {
  int64_t sb = k + 1;
  int64_t sr = k;

  // #ifdef LOCAL_DEBUG
  //   int64_t ans0 = 0;
  //   FOR(a, 0, n + 1)
  //   FOR(b, 1, n + 1) {
  //     int rem = a % b;
  //     if (rem >= k) {
  //       // DOUT(a, b);
  //       ans0 += 1;
  //     }
  //   }
  // #endif

  int64_t c0 = 0;
  if (k == 0) {
    c0 = n * n;
  } else {
    FOR(ssb, sb, n + 1) {
      int64_t na = n / ssb;
      int64_t ra = ssb - sr;
      int64_t nna = (n + ssb - 1) / ssb;

      c0 += ra * na;
      if (na != nna) {
        int64_t j = nna - 1;
        int64_t b = j * ssb + sr - 1;
        int64_t mb = b + ra + sr;
        if (mb > n) {
          mb = n;
        }
        if (mb > b) {
          c0 += mb - b;
        }
      }
    }

    // #ifdef LOCAL_DEBUG
    //     assert(ans0 == c0);
    // #endif
  }
  cout << c0 << endl;
}

int main() {
#ifdef LOCAL_DEBUG
  localout();
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
#else
  ios::sync_with_stdio(false);
#endif
  int64_t n, k;
  CIN2(n, k);
  RR(n, k);

  return 0;

  // FOR(n, 1, 1000 + 1) {
  //   FOR(k, 0, 999 + 1) {
  //     RR(n, k);
  //   }
  // }

  // return 0;
}
