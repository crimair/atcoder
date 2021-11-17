#include <bits/stdc++.h>

using namespace std;

// string msg = R"(
// 2018
// 218
// )";

string msg = R"(
2763
0
)";

void localout() {
  ofstream out("input.txt");
  out << msg.substr(1, -1);
}

/**************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool infcoins(int N, int A) {
  int rem = N % 500;
  if (rem <= A) {
    return true;
  } else {
    return false;
  }
}

int main() {
#ifdef LOCAL_DEBUG
  localout();
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
#endif
  int n, a;
  cin >> n;
  cin >> a;

  if (infcoins(n, a)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
