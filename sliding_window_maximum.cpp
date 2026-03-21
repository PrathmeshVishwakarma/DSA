#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> answer = {};
        stack<int> stk = {};
        for (int i = 0; i < k; i++) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        // for (int i = 0; i <= nums.size() - k; i++) {
        //     cout << nums[i] << " " << nums[i + 1] << " " << nums[i + 2] <<
        //     endl;
        // }
        //
        return answer;
    }
};

int main() {
    vector<int> input = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution soln;
    vector<int> answer = soln.maxSlidingWindow(input, k);
    for (int i : answer)
        cout << i << " ";
}
