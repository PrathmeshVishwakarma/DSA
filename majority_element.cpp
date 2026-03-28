#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int majority_element = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count <= 0)
                majority_element = nums[i];
            if (nums[i] != majority_element)
                count -= 1;
            else
                count += 1;
        }
        return majority_element;
    }
};
