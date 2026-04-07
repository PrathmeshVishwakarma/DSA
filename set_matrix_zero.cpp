#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        unordered_set<int> rows = {};
        unordered_set<int> columns = {};
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for (int row : rows) {
            vector<int> temp(matrix[0].size(), 0);
            matrix[row] = temp;
        }
        vector<int> sorted_columns(columns.begin(), columns.end());
        sort(sorted_columns.begin(), sorted_columns.end());
        for (int j : sorted_columns) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][j] = 0;
            }
        }
    }
};

int main() {
    Solution soln;
    vector<vector<int>> vec = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    soln.setZeroes(vec);
    for (vector<int> row : vec) {
        for (int i : row) {
            cout << i << " ";
        }
        cout << endl;
    }
}
