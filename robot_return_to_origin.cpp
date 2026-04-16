#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (char i : moves) {
            switch (i) {
            case 'U':
                y += 1;
                break;

            case 'D':
                y -= 1;
                break;
            case 'L':
                x -= 1;
                break;
            case 'R':
                x += 1;
                break;
            }
        }
        return x == 0 && y == 0;
    }
};

int main() {
    Solution soln;
    cout << soln.judgeCircle("UD");
    return 0;
}
