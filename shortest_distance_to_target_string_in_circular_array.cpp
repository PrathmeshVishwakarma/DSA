#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class Solution {
//   public:
//     int closestTarget(vector<string> &words, string target, int startIndex) {
//         int minimum = INT_MAX;
//         int n = words.size();
//         int i = startIndex;
//         bool found = false;
//
//         if (words[i] == target)
//             return 0;
//
//         // going right
//         i = (i + 1) % n;
//         while (i != startIndex) {
//             if (words[i] == target) {
//                 found = true;
//                 int diff = abs(i - startIndex);
//                 minimum = min(minimum, min(diff, n - diff));
//                 break;
//             }
//             i = (i + 1) % n;
//         }
//
//         if (!found)
//             return -1;
//
//         // going left
//         int j = startIndex - 1;
//         if (j == -1)
//             j = n - 1;
//
//         while (j != startIndex) {
//             if (words[j] == target) {
//                 int diff = abs(j - startIndex);
//                 minimum = min(minimum, min(diff, n - diff));
//                 break;
//             }
//             j--;
//             if (j == -1)
//                 j = n - 1;
//         }
//
//         return minimum;
//     }
// };

class Solution {
  public:
    int closestTarget(vector<string> words, string target, int start_index) {
        int minimum = INT_MAX;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int difference = abs(i - start_index);
                int distance = min(
                    difference, n - difference); // checking circular distance
                minimum = min(minimum, distance);
            }
        }
        return minimum == INT_MAX ? -1 : minimum;
    }
};

int main() {
    Solution soln;
    vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
    cout << soln.closestTarget(words, "hello", 1);
}
