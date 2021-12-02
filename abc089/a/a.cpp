#include <bits/stdc++.h>

using namespace std;

// string msg = R"(
// 3 3
// ..#
// #..
// ...
// )";

string msg = R"(
9
)";

void localout() {
  ofstream out("input.txt");
  out << msg.substr(1, -1);
}

/**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int grouping2(int n) {
  return int (n / 3);
}

int main() {
#ifdef LOCAL_DEBUG
  localout();
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
#endif
  int n;
  cin >> n;
  cout << grouping2(n) << endl;

  return 0;
}
