#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);

  vector<int> l1;
  unordered_map<int, int> m;

  int first, second;

  while (cin >> first >> second) {
    l1.push_back(first);
    m[second]++;
  }

  int res = 0;

  for (int i = 0; i < l1.size(); i++) {
    res += l1[i] * m[l1[i]];
  }

  cout << res << "\n";
}
