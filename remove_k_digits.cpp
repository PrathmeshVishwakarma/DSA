#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    string removeKdigits(string num, int k) {
        int removed = 0;
        stack<int> stk = {};
        string final = "";
        if (k == num.length()) {
            return "0";
        }
        for (int i = 0; i < num.length(); i++) {
            int current_number = num[i] - '0';
            while (!stk.empty() && current_number < stk.top() && removed < k) {
                stk.pop();
                removed += 1;
            }
            stk.push(current_number);
        }
        while (removed < k) {
            removed++;
            stk.pop();
        }
        while (!stk.empty()) {
            final.insert(0, to_string(stk.top()));
            stk.pop();
        }
        while (final[0] == '0' && final.length() != 1) {
            final.erase(0, 1);
        }
        return final;
    }
};

int main() {
    string num = "1234567";
    int k = 3;
    Solution soln;
    cout << soln.removeKdigits(num, k);
    return 0;
}
