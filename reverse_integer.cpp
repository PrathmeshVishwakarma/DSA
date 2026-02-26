#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
  public:
    int reverse(int x) {
        vector<int> digits = {};
        int answer = 0;
        if (x < 0) {
            x *= -1;
            while (x > 0) {
                digits.push_back(x % 10);
                x /= 10;
            }
            int power = digits.size() - 1;
            // cout << digits.size() << " " << digits[4] << endl;
            for (int i = 0; i < digits.size(); i++) {
                // cout << digits[i] << endl;
                answer += digits[i] * pow(10, power);
                power--;
            }
            return answer * -1;
        } else {
            while (x > 0) {
                digits.push_back(x % 10);
                x /= 10;
            }
            int power = digits.size() - 1;
            // cout << digits.size() << " " << digits[4] << endl;
            for (int i = 0; i < digits.size(); i++) {
                // cout << digits[i] << endl;
                answer += digits[i] * pow(10, power);
                power--;
            }
            return answer;
        }
        return -1;
    }
};
int main() {
    int x = -435;
    Solution soln;
    // cout << soln.reverse(x);
    int y = 3;
    y = y >> 1;
    cout << y;
    return 0;
}
