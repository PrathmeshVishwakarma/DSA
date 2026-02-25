#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Hint: It boils down to Summation of maximum of subarrays - summation of
// minimum of subarrays
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
            while (!stk.empty() && arr[i] > arr[stk.top()]) {
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
    long long sumSubarrayMaxs(vector<int> &arr) {
        long long total = 0;
        int n = arr.size();
        vector<int> pge = previous_greater_element(arr);
        vector<int> nge = next_greater_element(arr);
        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total += right * left * arr[i];
        }
        // for (int i : nge) {
        //     cout << i << " ";
        // }
        return total;
    }
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
    long long sumSubarrayMins(vector<int> &arr) {
        long long total = 0;
        int n = arr.size();
        int mod = (int)(1e9 + 7);
        vector<int> pse = previous_smaller_element(arr);
        vector<int> nse = next_smaller_element(arr);
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            // cout << left << " " << right * left * arr[i] << " " << right
            //      << endl;
            total += right * left * arr[i];
        }
        // for (int i : nse)
        //     cout << i << " ";
        return total;
    }
    long long subArrayRanges(vector<int> &nums) {
        long long answer = 0;
        long long summation_max = sumSubarrayMaxs(nums);
        long long summation_min = sumSubarrayMins(nums);
        answer = summation_max - summation_min;
        return answer;
    }
};

int main() {
    vector<int> vec = {1, 4, 3, 2};
    Solution soln;
    cout << soln.subArrayRanges(vec);
}
