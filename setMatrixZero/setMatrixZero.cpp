#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n;
        if (m == 0)
            return;
        else
            n = matrix[0].size();
        set<int> row, column;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    row.insert(i);
                    column.insert(j);
                }
            }
        set<int>::iterator it;
        for (it = row.begin(); it != row.end(); it++)
            for (int i = 0; i < n; i++)
                matrix[*it][i] = 0;
        for (it = column.begin(); it != column.end(); it++)
            for (int j = 0; j < m; j++)
                matrix[j][*it] = 0;
    }
};

int main() {
    Solution sln = Solution();
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {6,7,0,9,0};
    vector<int> c = {3,5,6,8,3};
    vector<vector<int>> matrix;
    matrix.push_back(a);
    matrix.push_back(b);
    matrix.push_back(c);

    sln.setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
