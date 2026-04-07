#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// class Solution {
//   public:
//     int subarraySum(vector<int> &nums, int k) {
//         /*
//          Intuition: read hints lol
//          Anyways, use prefix sum for example for array:
//         {1, 2, 3, -3, 1, 1, 1, 4, 2, -3}, k=3
//         {1, 3, 6, 3, 4, 5, 6, 10, 12, 9}
//         now we gotta find pairs with the difference of 3 between them.
//         Guess where we used same concept before, yes very first question: 2
//         sums! Use SETS!!!
//         */
//         if (nums.size() == 1) {
//             return nums[0] == k;
//         }
//         vector<int> prefix_sum = {};
//         unordered_set<int> s = {};
//         int count = 0;
//         for (int i : nums) {
//             if (prefix_sum.size() == 0) { // for the first element
//                 prefix_sum.push_back(i);
//                 s.insert(i);
//             } else {
//                 int push = prefix_sum[prefix_sum.size() - 1] + i;
//                 prefix_sum.push_back(push);
//                 s.insert(push);
//             }
//         }
//         for (int i : prefix_sum) {
//             if (s.find(i - k) != s.end() || i == k) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        /*
         Intuition: read hints lol
         Anyways, use prefix sum for example for array:
        {1, 2, 3, -3, 1, 1, 1, 4, 2, -3}, k=3
        {1, 3, 6, 3, 4, 5, 6, 10, 12, 9}
        now we gotta find pairs with the difference of 3 between them.
        Guess where we used same concept before, yes very first question: 2
        sums! Use SETS!!!

        previous approach was wrong: wrong on {1, -1, 1}
        */
        pmr::unordered_map<int, int> mp = {};
        mp[0] = 1;
        int current_sum = 0;
        int count = 0;

        for (int i : nums) {
            current_sum += i;
            if (mp.find(current_sum - k) != mp.end()) {
                count += mp[current_sum - k];
            }
            mp[current_sum]++;
        }
        return count;
    }
};

int main() {
    Solution soln;
    vector<int> vec = {1, -1, 1};
    cout << soln.subarraySum(vec, 1);
}
