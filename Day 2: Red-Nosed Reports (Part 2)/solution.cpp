#include <bits/stdc++.h>
using namespace std;

bool isValidVector(const vector<int>& report) {
    for (std::size_t i = 0; i < report.size(); ++i)
    {
        std::vector<int> filtered_report;
        
        // Filter the report based on the current index
        for (std::size_t j = 0; j < report.size(); ++j)
        {
            if (static_cast<int>(j) == i)
            {
                filtered_report.push_back(report[j]);
            }
        }

        // Check if the filtered report is either sorted in increasing or decreasing order
        bool is_increasing = std::is_sorted(filtered_report.begin(), filtered_report.end());
        bool is_decreasing = std::is_sorted(filtered_report.begin(), filtered_report.end(), std::greater<int>());

        if (!is_increasing && !is_decreasing)
            continue;

        // Calculate the absolute differences between adjacent elements
        std::vector<int> distances;
        distances.reserve(filtered_report.size());
        for (std::size_t j = 1; j < filtered_report.size(); ++j)
        {
            distances.push_back(std::abs(filtered_report[j] - filtered_report[j - 1]));
        }

        // Check if all distances (except the first one) are in the range (0, 4)
        bool valid_distances = true;
        for (std::size_t j = 1; j < distances.size(); ++j)
        {
            if (distances[j] <= 0 || distances[j] >= 4)
            {
                valid_distances = false;
                break;
            }
        }

        if (valid_distances)
            return true;
    }

    return false;
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
