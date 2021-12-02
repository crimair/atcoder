#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

// string msg = R"(
// 3
// 3 5 -1
// )";

// string msg = R"(
// 5
// 1 1 1 2 0
// )";

// string msg = R"(
// 6
// -679 -2409 -3258 3095 -3291 -4462
// )";

// string msg = R"(
// 3 8 2
// )";

string msg = R"(
2 9 100
)";

void localout() {
  ofstream out("input.txt");
  out << msg.substr(1, -1);
}

/****************
問題文
以下を満たす整数をすべて昇順に出力してください。

A 以上 B 以下の整数の中で、小さい方から K 番目以内であるか、大きい方から K
番目以内である
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

#define SORT(v) sort(v.begin(), v.end())
#define REVERSE(v) reverse(v.begin(), v.end())

// dictionary map<string, int> res;
#define MAP_FIND_HIT(m, key) (m.find(key) != m.end())
#define MAP_ALL(m, itr) for (auto itr = m.begin(); itr != m.end(); ++itr)

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

/**************************************************************/
int main() {
#ifdef LOCAL_DEBUG
  localout();
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
#else
  ios::sync_with_stdio(false);
#endif
  int a, b, k;
  CIN3(a, b, k);

  if ((b - a) >= (k * 2)) {
    FOR(i, a, a + k) {
      cout << i << endl;
    }
    FOR(i, b - k + 1, b + 1) {
      cout << i << endl;
    }
  } else {
    FOR(i, a, b + 1) {
      cout << i << endl;
    }
  }

  return 0;
}
