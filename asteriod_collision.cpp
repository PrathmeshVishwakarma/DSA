#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> asteroidCollision(vector<int> &arr) {
        vector<int> answer = {};
        stack<int> stk = {};
        for (int i = 0; i < arr.size(); i++) {
            if (!stk.empty() && stk.top() > 0 &&
                arr[i] < 0) { // only time it will conflict
                while (!stk.empty() && ((-1 * arr[i]) > stk.top()) &&
                       stk.top() > 0 &&
                       arr[i] < 0) { // make sure to remove only conflicting
                    stk.pop();
                }
                if (stk.top() == (-1 * arr[i])) {
                    stk.pop();
                } else if (stk.empty()) { // uda diya sabko left wale ne
                    stk.push(arr[i]);
                } else if (!stk.empty() &&
                           stk.top() >
                               0) { // right going is bigger than left going
                    continue;
                } else if (!stk.empty() &&
                           stk.top() < 0) { // left side meets left side
                    stk.push(arr[i]);
                }
            } else {
                stk.push(arr[i]);
            }
        }
        while (!stk.empty()) {
            answer.insert(answer.begin(), stk.top());
            stk.pop();
        }
        return answer;
    }
};

int main() {
    vector<int> vec = {5, 10, -5};
    Solution soln;
    vector<int> answer = soln.asteroidCollision(vec);
    for (int i : answer) {
        cout << i << " ";
    }
    return 0;
}
