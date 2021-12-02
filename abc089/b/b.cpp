#include <bits/stdc++.h>

using namespace std;

// string msg = R"(
// 3 3
// ..#
// #..
// ...
// )";

// string msg = R"(
// 6
// G W Y P Y W
// )";

// string msg = R"(
// 9
// G W W G P W P G G
// )";

string msg = R"(
8
P Y W G Y W Y Y
)";

    void
    localout() {
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
  int f = 0;
  rep(i, n) {
    char c;
    cin >> c;
    f |= (c == 'P') ? 0x1 : (c == 'W') ? 0x2 : (c == 'G') ? 0x4: 0x8;
  }
  if (f == 0xf){
    cout << "Four" << endl;
  }else{
    cout << "Three" << endl;
  }

  return 0;
}
