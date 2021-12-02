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

string msg = R"(
6
5 5 4 4 3 3
)";

void localout() {
  ofstream out("input.txt");
  out << msg.substr(1, -1);
}

/****************
問題文
N+1 個のマスが左右に一列に並んでいます． これらのマスには，左のマスから順に
0,1,...,N の番号が付けられています．

あなたは，最初マス X にいます． 隣り合うマスの間は自由に移動することができ，マス
0 またはマス N にたどり着くとゴールすることができます． ただし，i=1,2,...,M
について，マス A
i
​
  には料金所があり，そのためマス A
i
​
  に移動してくる際には 1 のコストがかかります． なお，マス 0，マス X，マス N
には料金所がないことが保証されます．

ゴールするまでにかかるコストの最小値を求めてください．

制約
1≤N≤100
1≤M≤100
1≤X≤N−1
1≤A 1 ​ <A 2 ​ <...<A M ​ ≤N−1 A i ​

=X
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
bool comp(p3& a, p3& b) {
  return a.x < b.x;
}
bool comp_index(p3& a, p3& b) {
  return a.z < b.z;
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

  auto x = V<p3>();
  REP(i, n) {
    int t;
    CIN(t);
    x.push_back(p3(i, 0, t));
  }

  sort(x.begin(), x.end(), comp);

  /*
    2 3 4 4
   */
  REP(i, n) {
    if (i < (n >> 1)) {
      x[i].y = x[n / 2].x;
    } else {
      x[i].y = x[n / 2 - 1].x;
    }
  }
  sort(x.begin(), x.end(), comp_index);

  REP(i, n) {
    cout << x[i].y << endl;
  }
  return 0;
}
