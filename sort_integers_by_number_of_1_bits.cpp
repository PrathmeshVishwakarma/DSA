#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    int bitcount(int n) {
        int count = 0;
        while (n > 0) {
            count = count + 1;
            n = n & (n - 1);
        }
        return count;
    }
    vector<int> sortByBits(vector<int> &arr) {
        vector<int> answer = {};
        // cout << bitcount(3) << endl;
        vector<pair<int, int>> pair_vector = {};
        for (int i : arr) {
            pair_vector.push_back({bitcount(i), i});
        }
        sort(pair_vector.begin(), pair_vector.end());
        for (const auto &p : pair_vector) {
            // std::cout << p.first << " " << p.second << "\n";
            answer.push_back(p.second);
        }
        return answer;
    }
};

int main() {
    vector<int> arr = {};
    Solution soln;
    vector<int> answer = soln.sortByBits(arr);
    return 0;
}
