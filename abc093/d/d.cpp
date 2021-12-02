#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

string msg = R"(
8
1 4
10 5
3 3
4 11
8 9
22 40
8 36
314159265 358979323
)";

// string msg = R"(
// 2 6 3
// )";

// string msg = R"(
// 31 41 5
// )";

void localout() {
  ofstream out("input.txt");
  out << msg.substr(1, -1);
}

/****************
問題文
3 つの整数 A,B,C が与えられます。以下の 2 種類の操作を好きな順で繰り返して A,B,C
をすべて等しくするために必要な操作の最小回数を求めてください。

A,B,C のうち 2 つを選んで、その両方を 1 増やす
A,B,C のうち 1 つを選んで、その整数を 2 増やす
なお、これらの操作を繰り返して A,B,C をすべて等しくできることは証明できます。

 **************/

/**************************************************************/

#include <bits/stdc++.h>

using namespace std;

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
#define DOUT(...) print_tuple(make_tuple(__VA_ARGS__))

#define VOUT(v)                         \
  for (auto& _a : v) cout << _a << ' '; \
  cout << endl
#define VOUT2(v)                           \
  for (auto& _a : v)                       \
    for (auto& _b : _a) cout << _b << ' '; \
  cout << endl

typedef int64_t ll;

/**************************************************************/
ll calc(ll a, ll b) {
  if (a == b) {
    return 2 * a - 2;
  }
  ll ta = min(a, b);
  ll tb = max(a, b);
  a = ta;
  b = tb;
  ll lo = a;
  ll hi = 2 * b;
  ll th = a * b;
  while ((hi - lo) > 1) {
    ll mid = (lo + hi) / 2;
    ll mul = (mid + 1) / 2 * (mid / 2 + 1);  //!!
    // ll mul = mid / 2 * (mid / 2 + 1);  //!!
    if (mul < th) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  // DOUT(a, b, lo, hi);
  return lo - 1;
}
int main() {
#ifdef LOCAL_DEBUG
  localout();
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
#else
  ios::sync_with_stdio(false);
#endif
  int q;
  CIN(q);

  REP(i, q) {
    ll a, b;
    CIN2(a, b);

    cout << calc(a, b) << endl;
  }

  return 0;
}
