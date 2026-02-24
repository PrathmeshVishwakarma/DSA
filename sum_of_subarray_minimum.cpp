#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Solution 1: O(n^2) time complexity
class Solution {
  public:
    int sumSubarrayMins(vector<int> &arr) {
        int total = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            stack<int> stk = {};
            for (int j = i; j < n; j++) {
                while (!stk.empty() && arr[j] <= stk.top()) {
                    stk.pop();
                }
                if (stk.empty()) { // current element is the minimum
                    total += arr[j];
                } else {
                    total += stk.top();
                }
                stk.push(arr[j]);
            }
        }
        return total;
    }
};

int main() {
    vector<int> vec = {3, 1, 2, 4};
    Solution soln;
    cout << soln.sumSubarrayMins(vec);
    return 0;
}
