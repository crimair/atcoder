#include <bits/stdc++.h>

#include <queue>

using namespace std;

string msg = R"(
3 6
0 0 1 0 0 0
1 0 1 0 1 0
0 0 0 0 1 0
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
int bfs(int h, int w, vector<vector<int>>& m, p2& s, p2& g) {
  auto openlist = QUE<p2>();
  auto closelist = V<p2>();

  int dx[4] = {0, -1, 0, 1};
  int dy[4] = {1, 0, -1, 0};

  openlist.push(s);
  int cost = 1;

  while (true) {
    auto tmpque = QUE<p2>();

    if (openlist.empty()) {
      return -1;
    }
    while (!openlist.empty()) {
      auto st = openlist.front();

      if (st == g) {
        return cost;
      }

      if (m[st.y][st.x] == 1) {
        // pass
      } else {
        bool check = true;
        for (auto p : closelist) {
          if (p == st) {
            check = false;
            break;
          }
        }

        if (check) {
          closelist.push_back(st);
          REP(i, 4) {
            int ny = st.y + dy[i];
            int nx = st.x + dx[i];

            if (0 <= nx && nx < w && 0 <= ny && ny < h) {
              tmpque.push(p2(ny, nx));
            }
          }
        }
      }

      openlist.pop();
    }
    while (!tmpque.empty()) {
      auto pt = tmpque.front();
      openlist.push(p2(pt.y, pt.x));
      tmpque.pop();
    }
    cost++;
  }

  return 0;
}

int main() {
#ifdef LOCAL_DEBUG
  localout();
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
#else
  ios::sync_with_stdio(false);
#endif
  int h, w;
  CIN2(h, w);
  auto m = VV<int>(h, w);
  VIN2(m);

  auto s = p2(0, 0);
  auto g = p2(h - 1, w - 1);

  int cost = bfs(h, w, m, s, g);

  cout << cost << endl;

  return 0;
}
