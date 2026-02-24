#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Solution 1 - use suffix_max and prefix_max array
class Solution {
  public:
    int trap(vector<int> &height) {
        int total = 0;
        int n = height.size();
        vector<int> suffix_max(n, -1);
        vector<int> prefix_max(n, -1);
        suffix_max[n - 1] = height[n - 1];
        prefix_max[0] = height[0];

        // calculating prefix_max
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(height[i], prefix_max[i - 1]);
        }

        // calculating suffix_max
        for (int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max(height[i], suffix_max[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            total += min(prefix_max[i], suffix_max[i]) - height[i];
        }
        return total;
    }
};

int main() {
    vector<int> vec = {2, 1, 0, 5, 3};
    Solution soln;
    cout << soln.trap(vec);
    return 0;
}
