#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1, 1, 0, 1, 1, 1};
    int counter = 0;
    int maximum = 0;
    for (int i : vec) {
        if (i == 1) {
            counter++;
            maximum = max(counter, maximum);
        } else {
            counter = 0;
        }
    }
    cout << maximum;
    return 0;
}
