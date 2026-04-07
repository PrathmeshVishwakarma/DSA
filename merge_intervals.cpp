#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer = {};
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (end >= intervals[i + 1][0]) {
                end = max(intervals[i + 1][1], end);
            } else {
                answer.push_back({start, end});
                start = intervals[i + 1][0];
                end = intervals[i + 1][1];
            }
        }
        answer.push_back({start, end});
        return answer;
    }
};

int main() {
    Solution soln;
    vector<vector<int>> vec = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vec = soln.merge(vec);
    for (vector<int> i : vec) {
        cout << i[0] << " " << i[1] << endl;
    }
}
