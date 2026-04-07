#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// class Solution {
//   public:
//     vector<int> majorityElement(vector<int> &nums) {
//         unordered_map<int, int> mp = {};
//         unordered_set<int> s = {};
//         int top = nums.size() / 3;
//         for (int i : nums) {
//             mp[i]++;
//             if (mp[i] > top) {
//                 s.insert(i);
//             }
//         }
//         return vector<int>(s.begin(), s.end());
//     }
// };

class Solution {
  public:
    vector<int> majorityElement(vector<int> &nums) {
        int count1 = 0, count2 = 0;
        int element1 = 0, element2 = 0;
        vector<int> answer = {};
        for (int i : nums) {
            if (count1 == 0 && i != element2) {
                count1++;
                element1 = i;
            } else if (count2 == 0 && i != element1) {
                count2++;
                element2 = i;
            } else if (i == element1)
                count1++;
            else if (i == element2)
                count2++;
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i : nums) {
            if (i == element1)
                count1++;
            if (i == element2)
                count2++;
        }
        if (count1 > nums.size() / 3)
            answer.push_back(element1);
        if (element2 != element1 && count2 > nums.size() / 3)
            answer.push_back(element2);
        return answer;
    }
};

int main() {
    vector<int> vec = {3, 2, 3};
    Solution soln;
    vec = soln.majorityElement(vec);
    for (int i : vec) {
        cout << i << " ";
    }
}
