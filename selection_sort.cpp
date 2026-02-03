#include <iostream>
#include <vector>
using namespace std;

int smallest_index(int starting_index, vector<int> vec);

// Selection sort
int main() {
    cout << "Hello" << endl;
    vector<int> vec = {13, 46, 24, 52, 20, 9};

    for (int i = 0; i < vec.size(); i++) {
        vector<int> sub(vec.begin() + i, vec.end());
        int index = smallest_index(i, sub);
        for (int j : vec) {
            cout << j << " ";
        }
        swap(vec[i], vec[index]);
        cout << "\t" << index << endl;
    }
}

int smallest_index(int starting_index, vector<int> vec) {
    int idx = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < vec[idx]) {
            idx = i;
        }
    }
    return starting_index + idx;
}
