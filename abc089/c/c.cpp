#include <bits/stdc++.h>

using namespace std;

// string msg = R"(
// 3 3
// ..#
// #..
// ...
// )";

// string msg = R"(
// 5
// MASHIKE
// RUMOI
// OBIRA
// HABORO
// HOROKANAI
// )";

// string msg = R"(
// 4
// ZZ
// ZZZ
// Z
// ZZZZZZZZZZ
// )";

// string msg = R"(
// 5
// CHOKUDAI
// RNG
// MAKOTO
// AOKI
// RINGO
// )";

string msg = R"(
7
CHOKUDAI
CHOKUDAI2
RNG
RNG
MAKOTO
MAKOTO2
MAKOTO2
)";

void localout() {
  ofstream out("input.txt");
  out << msg.substr(1, -1);
}

/**************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define fori(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) for(int i=0;i<(a);i++)

int main() {
#ifdef LOCAL_DEBUG
  localout();
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
#endif
  int n;
  cin >> n;
  int64_t march[5] = {0,0,0,0,0};
  rep(i, n) {
    string s;
    cin >> s;
    march[0] += (s[0] == 'M') ? 1 : 0;
    march[1] += (s[0] == 'A') ? 1 : 0;
    march[2] += (s[0] == 'R') ? 1 : 0;
    march[3] += (s[0] == 'C') ? 1 : 0;
    march[4] += (s[0] == 'H') ? 1 : 0;
  }

  int64_t ans = 0;

  // 5 * 2
  fori(k, 1, 4){
    fori(j, 1, 4) {
      fori(i, 0, 5) {
        int s0 = i;
        int s1 = s0 + j;
        int s2 = s1 + k;
        if (s1 < 5 && s2 < 5 && s0 != s1 && s1 != s2 && s2 != s0){
          ans += march[s0] * march[s1] * march[s2];
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
