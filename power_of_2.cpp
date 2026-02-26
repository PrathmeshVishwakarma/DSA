#include <iostream>

using namespace std;

class Solution {
  public:
    bool isPowerOfTwo(int n) {
        return __builtin_popcount(n) == 1 && n > 0 ? true : false;
    }
};

int main() {
    Solution soln;
    cout << soln.isPowerOfTwo(7);
}
