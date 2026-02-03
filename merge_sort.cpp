#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    int ptr1 = low;
    int ptr2 = mid + 1;
    vector<int> result = {};
    while (ptr1 <= mid && ptr2 <= high) {
        if (arr[ptr1] <= arr[ptr2]) {
            result.push_back(arr[ptr1]);
            ptr1++;
        } else {
            result.push_back(arr[ptr2]);
            ptr2++;
        }
    }
    while (ptr1 <= mid) {
        result.push_back(arr[ptr1]);
        ptr1++;
    }
    while (ptr2 <= high) {
        result.push_back(arr[ptr2]);
        ptr2++;
    }

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < result.size(); i++) {
        arr[low + i] = result[i];
    }
}
void merge_sort(vector<int> &arr, int low, int high) {
    if (low >= high) {
        // cout << arr[low] << " ";
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main() {
    vector<int> vec = {13, 46, 24, 52, 20, 9};
    vector<int> test = {1, 2, 4, 3, 5};
    merge_sort(vec, 0, vec.size() - 1);
    // merge(test, 0, 2, 4);
}
