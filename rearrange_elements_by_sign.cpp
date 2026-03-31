#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> rearrangeArray(vector<int> &nums) {
        vector<int> answer(nums.size(), 0);
        int positive = 0, negative = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) { // positive
                answer[positive] = nums[i];
                positive += 2;
            } else {
                answer[negative] = nums[i];
                negative += 2;
            }
        }
        return answer;
    }
};

int main() {
    Solution soln;
    vector<int> vec = {3, 1, -2, -5, 2, -4};
    vec = soln.rearrangeArray(vec);
    for (int i : vec) {
        cout << i << " ";
    }
}
