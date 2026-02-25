#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>

using namespace std;

// class Solution {
//   public:
//     vector<int> previous_smaller_element(vector<int> nums) {
//         int n = nums.size();
//         vector<int> pse(n, -1);
//         stack<int> stk = {};
//         for (int i = 0; i < n; i++) {
//             while (!stk.empty() && nums[i] <= nums[stk.top()]) {
//                 stk.pop();
//             }
//             if (stk.empty()) {
//                 pse[i] = -1;
//             } else {
//                 pse[i] = stk.top();
//             }
//             stk.push(i);
//         }
//         return pse;
//     }
//     vector<int> next_smaller_element(vector<int> nums) {
//         int n = nums.size();
//         stack<int> stk = {};
//         vector<int> nse(n, n);
//         for (int i = n - 1; i >= 0; i--) {
//             while (!stk.empty() && nums[i] < nums[stk.top()]) {
//                 stk.pop();
//             }
//             if (stk.empty()) {
//                 nse[i] = n;
//             } else {
//                 nse[i] = stk.top();
//             }
//             stk.push(i);
//         }
//         return nse;
//     }
//     int largestRectangleArea(vector<int> &heights) {
//         int n = heights.size();
//         int maximum_area = INT_MIN;
//         vector<int> pse = previous_smaller_element(heights);
//         vector<int> nse = next_smaller_element(heights);
//         for (int i = 0; i < n; i++) {
//             int current_area = heights[i] * (((i - pse[i]) + (nse[i] - i)) -
//             1); maximum_area = max(maximum_area, current_area);
//         }
//         return maximum_area;
//     }
// };

// Prototype 2: Calculating pse on the go, will cut time complexity from O(3n)
// -> O(2n)
class Solution {
  public:
    vector<int> next_smaller_element(vector<int> nums) {
        int n = nums.size();
        stack<int> stk = {};
        vector<int> nse(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] < nums[stk.top()]) {
                stk.pop();
            }
            if (stk.empty()) {
                nse[i] = n;
            } else {
                nse[i] = stk.top();
            }
            stk.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        int maximum_area = INT_MIN;
        stack<int> stk = {};
        vector<int> nse = next_smaller_element(heights);
        for (int i = 0; i < n; i++) {
            int pse = -1;
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            if (stk.empty()) {
                pse = -1;
            } else {
                pse = stk.top();
            }
            stk.push(i);
            int current_area = heights[i] * (((i - pse) + (nse[i] - i)) - 1);
            maximum_area = max(maximum_area, current_area);
        }
        return maximum_area;
    }
};

int main() {
    vector<int> nums = {2, 4};
    Solution soln;
    cout << soln.largestRectangleArea(nums);
    return 0;
}
