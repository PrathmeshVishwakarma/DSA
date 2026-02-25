#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
  public:
    vector<int> previous_greater_element(vector<int> arr) {
        int n = arr.size();
        stack<int> stk = {};
        vector<int> pge(n, -1);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[i] >= arr[stk.top()]) {
                stk.pop();
            }
            if (stk.empty()) {
                pge[i] = -1;
            } else {
                pge[i] = stk.top();
            }
            stk.push(i); // entering the indexes
        }
        return pge;
    }
    vector<int> next_greater_element(vector<int> arr) {
        int n = arr.size();
        stack<int> stk = {};
        vector<int> nge(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[i] >= arr[stk.top()]) {
                stk.pop();
            }
            if (stk.empty()) {
                nge[i] = n;
            } else {
                nge[i] = stk.top();
            }
            stk.push(i);
        }
        return nge;
    }
    int sumSubarrayMaxs(vector<int> &arr) {
        long long total = 0;
        int n = arr.size();
        int mod = (int)(1e9 + 7);
        vector<int> pge = previous_greater_element(arr);
        vector<int> nge = next_greater_element(arr);
        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total = (total + (right * left * arr[i]) % mod) % mod;
        }
        // for (int i : nge) {
        //     cout << i << " ";
        // }
        return (int)total;
    }
};
int main() {
    vector<int> vec = {1, 4, 3, 2};
    Solution soln;
    cout << soln.sumSubarrayMaxs(vec);
    return 0;
}
