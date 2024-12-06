#include <bits/stdc++.h>
using namespace std;


bool isValidVector(const vector<int>& v) {
    bool increasing = true, decreasing = true;

    for (int i = 1; i < v.size(); i++) {
        int diff = abs(v[i] - v[i - 1]);

        if (diff < 1 || diff > 3) return false;

        if (v[i] > v[i - 1]) decreasing = false;
        if (v[i] < v[i - 1]) increasing = false;

        if (!increasing && !decreasing) return false;
    }

    return true;
}

int main() {
  ifstream file("input.txt");

  int res = 0;
  string line;

  while (getline(file, line)) {
    istringstream iss(line);

    vector<int> vec;
    int num;

    while (iss >> num) {
      vec.push_back(num);
    }

    if (isValidVector(vec)) res++;
  }

  cout << res << "\n";
}
