#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        stack<int> stk = {};
        vector<int> answer(nums.size(), -1);
        for (int i=nums.size()-1; i>=0; i--){
            while (!stk.empty() && nums[i] <= stk.top()){
                stk.pop();
            }
            if (stk.empty()){
                answer[i] = 0;
            } else {
                answer[i] = stk.size();
            }
            stk.push(nums[i]);
        }
        return answer;
    }
};

int main(){
    vector<int> nums = {5,2,6,1};
    Solution soln;
    vector<int> answer = soln.countSmaller(nums);
    for (int i: answer) cout << i << " ";
    return 0;
}
