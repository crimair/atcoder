#include <bits/stdc++.h>

#include <algorithm>
#include <string>

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
//
// )";

// string msg = R"(
// 3 34
// 1
// 8 13 26
// )";

// string msg = R"(
// 7 45
// 2
// 7 11 16 20 28 34 38
// )";

// string msg = R"(
// 3 100
// 1
// 28 54 81
// )";

string msg = R"(
20
)";

// string msg = R"(
// 20 1000
// 4
// 51 69 102 127 233 295 350 388 417 466 469 523 553 587 720 739 801 855 926 954
// )";

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

#define AOUT(...) print_tuple(make_tuple(__VA_ARGS__))

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
  int n;
  CIN(n);

  if (n & 1) {
    return 0;
  }

  uint32_t d = (1 << (n / 2)) - 1;
  int n2 = n / 2;
  // 0011
  // 0101

  // 000111
  // 001101
  // 010101

  // 00001111
  // 00011101
  // 00110101
  /*
   * (を0,)を1に置き換える
   * 最下位bitは必ず1
   * 最上位bitは必ず0
   * 値は+=2の範囲でしか変化させる必要がない
   */
  for (;; d += 2) {
    if (d >> (n - 1)) break;
    int c = 0;
    uint32_t dn = ~d;
    int f = 0;
    for (int i = n - 1; i >= 0; i--) {
      c += ((dn >> i) & 1);
      c -= ((d >> i) & 1);
      if (c < 0) {
        f = 1;
        break;
      } else if (c > n2) {
        f = 1;
        break;
      }
    }
    if (f == 0 && c == 0) {
      for (int i = n - 1; i >= 0; i--) {
        char chr = ((d >> i) & 1) ? ')' : '(';
        cout << chr;
      }
      cout << endl;
    }
  }

  return 0;
}
