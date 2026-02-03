#include <iostream>
#include <vector>
using namespace std;

// Insertion sort
int main() {
    vector<int> vec = {13, 46, 24, 52, 20, 9};
    for (int i = 0; i < vec.size(); i++) {
        int j = i;
        while (j > 0 && vec[j - 1] > vec[j]) {
            swap(vec[j], vec[j - 1]);
            j--;
        }
        for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
