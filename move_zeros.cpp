#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {0, 1, 0, 3, 12};
    int j = -1;

    // finding the first index of 0
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        return 0;
    }

    for (int i = j + 1; i < vec.size(); i++) {
        if (vec[i] != 0) {
            swap(vec[j], vec[i]);
            j++; // j++ as, if a number is beside 0, it will be right, if 0 se
                 // next to 0, it will be right. Draw the process, it will
                 // click!
        }
    }
    for (int i : vec) {
        cout << i << " ";
    }
}
