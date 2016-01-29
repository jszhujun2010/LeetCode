#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int round = n/2;
        int temp;
        for (int k = 0; k < round; k++) {
            for (int i = k; i < n-k-1; i++) {
                temp = matrix[k][i];
                matrix[k][i] = matrix[n-i-1][k];
                matrix[n-i-1][k] = matrix[n-k-1][n-i-1];
                matrix[n-k-1][n-i-1] = matrix[i][n-k-1];
                matrix[i][n-k-1] = temp;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Solution sln = Solution();
    sln.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
