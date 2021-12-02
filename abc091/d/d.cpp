#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

// string msg = R"(
// 2
// 1 2
// 3 4
// )";

string msg = R"(
5
1 2 3 4 5
1 2 3 4 5
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
int a[200000];
int b[200000];

int check_bit(int n, int d) {
  int maskh = (1 << d);
  int maskl = (1 << d) - 1;
  auto aa = V<int>(0);
  auto bb0 = V<int>(0);
  auto bb1 = V<int>(0);

  REP(i, n) {
    aa.push_back(a[i] & maskl);
  }

  //確認したい位置のbitが0 or 1で振り分け
  REP(i, n) {
    int ta = b[i] & maskh;
    if (ta == 0) {
      bb0.push_back(b[i] & maskl);  // bit = 0
    } else {
      bb1.push_back(b[i] & maskl);  // bit = 1
    }
  }

  //要事前ソート
  SORT(bb0);
  SORT(bb1);

  int cc = 0;
  REP(i, n) {
    int sel = a[i] & maskh;
    int th = maskh - aa[i];
    //下位bitからのcarryが発生しないのが何個あるか
    // lower_bound
    // 指定された要素以上の値が現れる最初の位置のイテレータを取得する
    int c0 = lower_bound(bb0.begin(), bb0.end(), th) - bb0.begin();  // index
    int c1 = lower_bound(bb1.begin(), bb1.end(), th) - bb1.begin();  // index
    // aの該当bitに対して1になるものを数える
    if (sel) {
      cc += c0;               // 1^0^carry=0^b=0
      cc += bb1.size() - c1;  // 1^1^carry=1^b=1
    } else {
      cc += bb0.size() - c0;  // 0^0^carry=1
      cc += c1;               // 0^1^carry=0
    }
  }
  return cc & 1;
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

  REP(i, n) {
    CIN(a[i]);
  }
  REP(i, n) {
    CIN(b[i]);
  }

  int ans = 0;
  REP(d, 29) {
    ans += check_bit(n, d) << d;
  }
  cout << ans << endl;

  return 0;
}
