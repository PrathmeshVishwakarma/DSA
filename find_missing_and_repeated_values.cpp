#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// class Solution {
//   public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
//         vector<int> answer = {0, 0};
//         unordered_set<int> s = {};
//         for (int i = 1; i <= grid.size() * grid.size(); i++) {
//             s.insert(i);
//         }
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid.size(); j++) {
//                 if (s.find(grid[i][j]) == s.end()) {
//                     answer[0] = grid[i][j];
//                     continue;
//                 }
//                 s.erase(grid[i][j]);
//             }
//         }
//         answer[1] = *s.begin();
//         return answer;
//     }
// };

// class Solution {
//   public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
//         vector<int> hash(grid.size() * grid.size(), 0);
//         vector<int> answer = {0, 0};
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid.size(); j++) {
//                 if (hash[grid[i][j] - 1] == 1) {
//                     answer[0] = grid[i][j];
//                     continue;
//                 }
//                 hash[grid[i][j] - 1]++;
//             }
//         }
//         for (int i = 0; i < hash.size(); i++) {
//             if (hash[i] == 0) {
//                 answer[1] = i + 1;
//                 break;
//             }
//         }
//         return answer;
//     }
// };

class Solution {
  public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
        /*
            Intuition: take array: {(1,3), (2,2)}
            {1+3+2+2} - {1+2+3+4} = 2-4 = Repeated - Missing = X - Y
            {1^2 + 3^2 + 2^2 + 2^2} - {1^2 + 2^2 + 3^2 + 4^2} = 2^2 - 4^2 = X^2
           - Y^2 = (X+Y)(X-Y) and as X-Y is known X+Y is attainable so adding
           them both you get 2X, so you will get X, Y
        */
        long long n = grid.size() * grid.size();
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
        long long S = 0, S2 = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                S += grid[i][j];
                S2 += grid[i][j] * grid[i][j];
            }
        }
        long long val1 = S - SN; // x- y
        long long val2 = S2 - S2N;
        val2 = val2 / val1;
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
        return {(int)x, (int)y};
    }
};

int main() {
    Solution soln;
    vector<vector<int>> vec = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> ans = soln.findMissingAndRepeatedValues(vec);
    cout << ans[0] << " " << ans[1];
}
