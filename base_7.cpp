#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string convertToBase7(int num) {
        string s;
        int x = num;
        if (x == 0)
            return "0";
        if (x < 0)
            num = num * -1;
        while (num > 0) {
            s.insert(0, to_string(num % 7));
            num = num / 7;
        }
        s = x < 0 ? '-' + s : s;
        return s;
    }
};

int main() {
    Solution soln;
    cout << soln.convertToBase7(0);
    return 0;
}
