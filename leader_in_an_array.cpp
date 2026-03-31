#include <climits>
#include <iostream>
#include <vector>

using namespace std;

vector<int> leader(vector<int> arr) {
    vector<int> answer = {};
    int maximum = INT_MIN;
    for (int i = arr.size() - 1; i >= 0; i--) {
        maximum = max(maximum, arr[i]);
        if (arr[i] == maximum)
            answer.insert(answer.begin(), arr[i]);
    }
    return answer;
}

int main() {
    vector<int> nums = {10, 22, 12, 3, 0, 6};
    nums = leader(nums);
    for (int i : nums) {
        cout << i << " ";
    }
}
