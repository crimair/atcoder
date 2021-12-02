#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

// string msg = R"(
// 4
// 2 4 4 3
// )";

// string msg = R"(
// 2
// 1 2
// )";

// string msg = R"(
// 5
// 6 9 4 2 11
// )";

string msg = R"(
2
100 0
)";

void localout() {
  ofstream out("input.txt");
  out << msg.substr(1, -1);
}

/****************
問題文
n 個のものから順番を無視して r 個を選ぶ場合の数を comb(n,r) と書くことにします。
n 個の非負の整数 a 1 ​ ,a 2 ​ ,...,a n ​ から 2 つの数 a i ​ >a j ​
を comb(a i ​ ,a j ​) が最大になるように選んで下さい。
最大になる組が複数ある場合、どれを選んでも構いません。

制約
2≤n≤10
5 0≤a i ​ ≤10 9
a 1 ​ ,a 2 ​ ,...,a n ​ は互いに相異なる
入力はすべて整数

 **************/

/**************************************************************/

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
int _debug = 1;
#else
int _debug = 0;
#endif

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
#define DOUT(...) \
  if (_debug) print_tuple(make_tuple(__VA_ARGS__))

#define VOUT(v)                         \
  for (auto& _a : v) cout << _a << ' '; \
  cout << endl
#define VOUT2(v)                           \
  for (auto& _a : v)                       \
    for (auto& _b : _a) cout << _b << ' '; \
  cout << endl

typedef int64_t ll;

/**************************************************************/
ll comb(ll i, ll j) {
  ll a = 1;
  ll b = 1;
  REP(ii, j) {
    a *= i - ii;
    b *= j - ii;
  }
  a /= b;
  return a;
}
int main() {
#ifdef LOCAL_DEBUG
  localout();
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
#else
  ios::sync_with_stdio(false);
#endif
  int n;
  CIN(n);

  auto x = V<ll>();
  ll maxa = 0;
  int maxi = 0;
  REP(i, n) {
    ll t;
    CIN(t);
    x.push_back(t);
    if (maxa < t) {
      maxa = t;
      maxi = i;
    }
  }
  ll ha = maxa / 2;
  ll dif = maxa;
  ll nv;
  // even
  if ((maxa & 1) == 0) {
    REP(i, n) {
      if (i != maxi) {
        ll dif0 = abs(x[i] - ha);
        if (dif > dif0) {
          nv = x[i];
          dif = dif0;
        }
      }
    }
    cout << maxa << ' ' << nv << endl;
  }
  // odd
  else {
    REP(i, n) {
      if (i != maxi) {
        ll dif0 = abs(x[i] - ha);
        if (x[i] == (ha + 1)) {
          nv = x[i];
          dif = 0;
        } else {
          if (dif > dif0) {
            nv = x[i];
            dif = dif0;
          }
        }
      }
    }
    cout << maxa << ' ' << nv << endl;
  }

  // ll res = 0;
  // ll ai;
  // ll aj;
  // REP(j, n) {
  //   REP(i, n) {
  //     if (i != j && x[i] > x[j]) {
  //       ll res0 = comb(x[i], x[j]);
  //       if (res < res0) {
  //         res = res0;
  //         ai = x[i];
  //         aj = x[j];
  //       }
  //     }
  //   }
  // }
  // DOUT(res, ai, aj);

  // int tt = 17;
  // FOR(i, 1, tt) {
  //   ll res0 = comb(tt, i);
  //   DOUT(tt, i, res0);
  // }
  return 0;
}
