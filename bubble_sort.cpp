#include <iostream>
#include <vector>
using namespace std;

// Bubble sort
int main() {
    vector<int> vec = {13, 46, 24, 52, 20, 9};
    for (int i = vec.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
        for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
}
