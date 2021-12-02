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

string msg = R"(
15 10000000000
400000000 1000000000
800000000 1000000000
1900000000 1000000000
2400000000 1000000000
2900000000 1000000000
3300000000 1000000000
3700000000 1000000000
3800000000 1000000000
4000000000 1000000000
4100000000 1000000000
5200000000 1000000000
6600000000 1000000000
8000000000 1000000000
9300000000 1000000000
9700000000 1000000000
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
#define REP(i, a) for (int i = 0; i < (a); i++)
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
  ll n, c;
  CIN2(n, c);
  auto tt = V<pt2<ll>>(n);
  REP(i, n) {
    ll x, v;
    CIN2(x, v);
    tt[i].x = x;
    tt[i].y = v;
  }
  auto tr = V<pt2<ll>>(n + 1);
  auto tl = V<pt2<ll>>(n + 1);
  tr[0].x = tr[0].y = 0;
  tl[0].x = tl[0].y = 0;
  ll prx = 0;
  ll plx = c;
  REP(i, n) {
    ll prxx = tt[i].x - prx;
    ll plxx = plx - tt[n - i - 1].x;
    prx = tt[i].x;
    plx = tt[n - i - 1].x;
    tr[i + 1].x = tr[i].x + tt[i].y - prxx;
    tr[i + 1].y = tr[i].y + tt[i].y - 2 * prxx;
    tl[i + 1].x = tl[i].x + tt[n - i - 1].y - plxx;
    tl[i + 1].y = tl[i].y + tt[n - i - 1].y - 2 * plxx;
  }
  // VOUT(tr);

  auto trm = V<ll>(n + 1);
  auto tlm = V<ll>(n + 1);
  trm[0] = 0;
  tlm[0] = 0;
  REP(i, n) {
    trm[i + 1] = max(trm[i], tr[i + 1].x);
    tlm[i + 1] = max(tlm[i], tl[i + 1].x);
  }

  ll maxv = 0;
  REP(i, n) {  //折返し位置
    ll max0 = tl[i].y + trm[n - i];
    ll max1 = tr[i].y + tlm[n - i];
    maxv = max(maxv, max0);
    maxv = max(maxv, max1);
    // DOUT(max0, max1, tl[i].y, tl[i].x, tr[3].y, tr[3].x, n, n - gn - i,
    // i);
    // REP(gn, n - i + 1) {  //抜ける位置
    //   ll max0 = tl[i].y + tr[n - gn - i].x;
    //   ll max1 = tr[i].y + tl[n - gn - i].x;
    //   maxv = max(maxv, max0);
    //   maxv = max(maxv, max1);
    //   // DOUT(max0, max1, tl[i].y, tl[i].x, tr[3].y, tr[3].x, n, n - gn - i,
    //   // i);
    // }
  }
  cout << maxv << endl;

  return 0;
}
