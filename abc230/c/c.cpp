#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

// string msg = R"(
// 1500 2000 1600 3 2
// )";

// string msg = R"(
// 3 20
// 2 80
// 9 120
// 16 1
// )";

// string msg = R"(
// 1 100000000000000
// 50000000000000 1
// )";

// string msg = R"(
// 5 3 2
// 1 5 1 5
// )";

// string msg = R"(
// 5 3 3
// 4 5 2 5
// )";

string msg = R"(
1000000000000000000 999999999999999999 999999999999999999
999999999999999998 1000000000000000000 999999999999999998 1000000000000000000
)";

void localout() {
  ofstream out("input.txt");
  out << msg.substr(1, -1);
}

/****************
 **************/

/**************************************************************/

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
int _debug = 1;
#else
int _debug = 0;
#endif

typedef int64_t ll;
#define imax ((1U << 31) - 1U)
#define llmax ((1ULL << 63) - 1ULL)

template <class T = int>
inline vector<T> V(int size = 0) {
  return vector<T>(size);
}
template <class T = int>
inline queue<T> QUE() {
  return queue<T>();
}
template <class T = int>
inline priority_queue<T> HQUE() {
  return priority_queue<T>();
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

template <typename T = int>
struct pt2 {
  T y;
  T x;

  pt2() {
  }
  pt2(T yi, T xi) : y{yi}, x{xi} {
  }
  bool operator==(const pt2<T>& other) {
    return (y == other.y && x == other.x);
  }
};

ostream& operator<<(ostream& os, const pt2<int>& g) {
  return os << "(" << g.x << "," << g.y << ")";
}
ostream& operator<<(ostream& os, const pt2<ll>& g) {
  return os << "(" << g.x << "," << g.y << ")";
}

template <typename T = int>
struct pt3 {
  T z;
  T y;
  T x;

  pt3() {
  }
  pt3(T zi, T yi, T xi) : z{zi}, y{yi}, x{xi} {
  }

  bool operator==(const pt3<T>& other) {
    return (z == other.z && y == other.y && x == other.x);
  }
};

ostream& operator<<(ostream& os, const pt3<int>& g) {
  return os << "(" << g.x << "," << g.y << "," << g.z << ")";
}
ostream& operator<<(ostream& os, const pt3<ll>& g) {
  return os << "(" << g.x << "," << g.y << "," << g.z << ")";
}

typedef pt2<int> p2;
typedef pt3<int> p3;

// macro
#define CIN(a) cin >> a
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define CIN4(a, b, c, d) cin >> a >> b >> c >> d
#define COUT(a) cout << (a)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORLL(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define REPLL(i, a) for (ll i = 0; i < (a); i++)
#define ENUMRATE(i, it, a) \
  int i = 0;               \
  for (auto it = a.begin(); it != a.end(); i++, ++it)

#define VIN(v) \
  for (auto& _a : v) cin >> _a
#define VIN2(v)      \
  for (auto& _a : v) \
    for (auto& _b : _a) cin >> _b

#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())

// dictionary map<string, int> res;
#define MAP_FIND_HIT(m, key) ((m).find(key) != (m).end())
#define MAP_ALL(m, itr) for (auto itr = (m).begin(); itr != (m).end(); ++itr)

#define Yes(f) cout << ((f) ? "Yes" : "No") << endl
#define YES(f) cout << ((f) ? "YES" : "NO") << endl

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
#define DOUT(...) \
  if (_debug) print_tuple(make_tuple(__VA_ARGS__))

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
  ll n, a, b;
  CIN3(n, a, b);
  ll p, q;
  ll r, s;
  CIN2(p, q);
  CIN2(r, s);

  ll k00, k01;
  k00 = max(1 - a, 1 - b);
  k01 = min(n - a, n - b);
  ll k10, k11;
  k10 = max(1 - a, b - n);
  k11 = min(n - a, b - 1);

  auto xb0 = V<int>(s + 1 - r);
  auto xb1 = V<int>(s + 1 - r);
  auto xk0 = V<ll>(s + 1 - r);
  auto xk1 = V<ll>(s + 1 - r);
  FORLL(j, r, s + 1) {
    xk0[j - r] = j - b;
    xk1[j - r] = -j + b;
    xb0[j - r] = k00 <= xk0[j - r] && xk0[j - r] <= k01 ? 1 : 0;
    xb1[j - r] = k10 <= xk1[j - r] && xk1[j - r] <= k11 ? 1 : 0;
  }

  FORLL(i, p, q + 1) {
    int yb0;
    int yb1;
    ll yk0;
    ll yk1;
    yk0 = i - a;
    yk1 = i - a;
    yb0 = k00 <= yk0 && yk0 <= k01 ? 1 : 0;
    yb1 = k10 <= yk1 && yk1 <= k11 ? 1 : 0;
    REPLL(j, s + 1 - r) {
      if ((xb0[j] & yb0 & (yk0 == xk0[j])) | (xb1[j] & yb1 & (yk1 == xk1[j]))) {
        cout << '#';
      } else {
        cout << '.';
      }
    }
    cout << endl;
  }

  return 0;
}
