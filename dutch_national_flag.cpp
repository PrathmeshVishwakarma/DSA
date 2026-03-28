#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void sortColors(vector<int> &arr) {
        int n = arr.size();
        int low = 0, mid = 0;
        int high = n - 1;

        // Loop mid through the unsorted array
        while (mid < high) {
            if (arr[mid] == 0) {
                swap(arr[mid], arr[low]);
                low++, mid++;
            } else if (arr[mid] == 1) {
                mid++;
            } else if (arr[mid] == 2) {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
int main() {
    Solution soln;
    vector<int> vec = {2, 0, 2, 1, 1, 0};
    soln.sortColors(vec);
    for (int i : vec) {
        cout << i << " ";
    }
}
