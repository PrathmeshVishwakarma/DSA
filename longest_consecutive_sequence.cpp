#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maximum = 0;
        int current = 1;
        for (int i : s) {
            if (s.find(i - 1) == s.end()) { // not found, first of the series
                while (s.find(i + 1) != s.end()) {
                    current += 1;
                    i++;
                }
            }
            maximum = max(maximum, current);
            current = 1;
        }
        return maximum;
    }
};

int main() {
    Solution soln;
    vector<int> vec = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << soln.longestConsecutive(vec);
}
