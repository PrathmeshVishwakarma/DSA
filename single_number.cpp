#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {4, 5, 4, 1, 2, 1, 2};
    int result = 0;
    for (int i = 0; i < vec.size(); i++) {
        result = result ^ vec[i];
    }
    cout << result;
    return 0;
}
