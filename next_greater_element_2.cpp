#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk = {};
        vector<int> answer(n, -1);
        for (int i=n*2-1; i>=0; i--){
            while (!stk.empty() && stk.top() <= nums[i%n]){
                stk.pop();
            }
            if (stk.empty() && i<n) {
                answer[i] = -1;
            } else if (!stk.empty() && i<n) {
                answer[i] = stk.top();
            }
            stk.push(nums[i%n]);
        } 
        return answer;
    }
};

int main(){
    vector<int> nums = {2, 10, 12, 1, 11};
    Solution soln;
    vector<int> answer = soln.nextGreaterElements(nums);
    for (int i: answer) cout << i << " ";
    return 0;
}
