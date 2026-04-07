#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        /*
         Intuition: Go over suffix and prefix of multiplication
         the maximum multiplacation is the answer
         if 0, drop the current_product, make it 1
        */
        int maximum = INT_MIN;
        int product = 1;

        // prefix
        for (int i : nums) {
            if (i == 0) {
                product = 1;
            } else {
                product *= i;
                maximum = max(maximum, product);
            }
        }

        product = 1;
        // suffix
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                product = 1;
            } else {
                product *= nums[i];
                maximum = max(maximum, product);
            }
        }
        return maximum;
    }
};

int main() {
    Solution soln;
    vector<int> vec = {2, 3, -2, 4};
    cout << soln.maxProduct(vec);
}
