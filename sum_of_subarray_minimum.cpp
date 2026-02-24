#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
// Solution 1: O(n^2) time complexity
class Solution {
  public:
    int sumSubarrayMins(vector<int> &arr) {
        int total = 0;
        int n = arr.size();
        int mod = (int)(1e9 + 7);
        for (int i = 0; i < n; i++) {
            stack<int> stk = {};
            int minimum = arr[i];
            for (int j = i; j < n; j++) {
                minimum = min(minimum, arr[j]);
                total = (total + minimum) % mod;
            }
        }
        return total;
    }
};
*/

// Solution 2: O(n) time complexity, using next and previous smaller element
class Solution {
  public:
    vector<int> previous_smaller_element(vector<int> arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> stk = {};
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = stk.top();
            }
            stk.push(i); // we want to return the vector of indexes of pse's
        }
        return pse;
    }

    vector<int> next_smaller_element(vector<int> arr) {
        int n = arr.size();
        vector<int> nse(n, -1);
        stack<int> stk = {};
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[i] <= arr[stk.top()]) {
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
    int sumSubarrayMins(vector<int> &arr) {
        long long total = 0;
        int n = arr.size();
        int mod = (int)(1e9 + 7);
        vector<int> pse = previous_smaller_element(arr);
        vector<int> nse = next_smaller_element(arr);
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            cout << left << " " << right * left * arr[i] << " " << right
                 << endl;
            total = (total + (right * left * arr[i]) % mod) % mod;
        }
        // for (int i : nse)
        //     cout << i << " ";
        return (int)total;
    }
};

int main() {
    vector<int> vec = {3, 1, 2, 4};
    Solution soln;
    cout << soln.sumSubarrayMins(vec);
    return 0;
}
