#include <bits/stdc++.h>

using namespace std;

// string msg = R"(
// 3
// apple
// orange
// apple
// 1
// grape
// )";

// string msg = R"(
// 6
// red
// red
// blue
// yellow
// yellow
// red
// 5
// red
// red
// yellow
// green
// blue
// )";

string msg = R"(
3
apple
orange
apple
5
apple
apple
apple
apple
apple
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
  int n, m;
  map<string, int> res;
  CIN(n);
  REP(i, n) {
    string s;
    CIN(s);
    if (MAP_FIND_HIT(res, s)) {
      res[s] += 1;
    } else {
      res[s] = 1;
    }
  }
  CIN(m);
  REP(i, m) {
    string s;
    CIN(s);
    if (MAP_FIND_HIT(res, s)) {
      res[s] -= 1;
    } else {
      res[s] = -1;
    }
  }

  int smax = 0;
  MAP_ALL(res, it) {
    smax = max(smax, it->second);
  }
  cout << smax << endl;

  return 0;
}
