#include <iostream>
#include <vector>

using namespace std;

// class MinStack {
//     // int top = -1;
//     vector<pair<int, int>> stk = {};
//
//   public:
//     MinStack() {}
//
//     void push(int val) {
//         if (stk.size() == 0) {
//             pair<int, int> push = {val, val};
//             stk.push_back(push);
//         } else {
//             int minimum = min(val, getMin());
//             pair<int, int> push = {val, minimum};
//             stk.push_back(push);
//         }
//     }
//
//     void pop() { stk.pop_back(); }
//
//     int top() { return stk.at(stk.size() - 1).first; }
//
//     int getMin() { return stk.at(stk.size() - 1).second; }
// };

class MinStack {
    vector<int> stk = {};
    vector<int> min_stk = {};

  public:
    MinStack() {}
    void push(int val) {
        if (min_stk.size() == 0 || val < min_stk.back()) {
            min_stk.push_back(val);
        }
        stk.push_back(val);
    }
    void pop() {
        if (min_stk.back() == stk.back()) {
            min_stk.pop_back();
        }
        stk.pop_back();
    }
    int top() { return stk.back(); }
    int getMin() { return min_stk.back(); }
};
int main() {
    MinStack *ms = new MinStack();
    vector<int> v = {1, 2, 3};
    cout << v.at(v.size() - 1);
}
