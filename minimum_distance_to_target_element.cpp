#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int getMinDistance(vector<int> &nums, int target, int start) {
        int minimum = INT_MAX;
        if (nums[start] == target)
            return 0;

        for (int i = start; i < nums.size(); i++) {
            if (nums[i] == target) {
                minimum = min(minimum, abs(i - start));
                break;
            }
        }

        for (int i = start; i >= 0; i--) {
            if (nums[i] == target) {
                minimum = min(minimum, abs(i - start));
                break;
            }
        }
        return minimum;
    }
};

int main() {
    Solution soln;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << soln.getMinDistance(nums, 5, 3);
}
