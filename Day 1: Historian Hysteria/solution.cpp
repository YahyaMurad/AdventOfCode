#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);

  vector<int> l1;
  vector<int> l2;
  
  int first, second;

  while (cin >> first >> second) {
    l1.push_back(first);
    l2.push_back(second);
  }

  sort(l1.begin(), l1.end());
  sort(l2.begin(), l2.end());

  int res = 0;

  for (int i = 0; i < l1.size(); i++) {
    res += abs(l1[i] - l2[i]);
  }

  cout << res << "\n";
}
