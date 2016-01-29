#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int odd = n%2;
        int k = n/2;
        vector<vector<int>> result;
        int x = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                temp.push_back(0);
            }
            result.push_back(temp);
        }

        for (int i = 0; i < k; i++) {
            for (int l1 = i; l1 < n-i-1; l1++)
                result[i][l1] = ++x;
            for (int l1 = i; l1 < n-i-1; l1++)
                result[l1][n-i-1] = ++x;
            for (int l1 = i; l1 < n-i-1; l1++)
                result[n-i-1][n-l1-1] = ++x;
            for (int l1 = i; l1 < n-i-1; l1++)
                result[n-l1-1][i] = ++x;
        }
        if (odd)
            result[k][k] = ++x;
        return result;
    }
};

int main() {
    Solution sln = Solution();
    vector<vector<int>> result = sln.generateMatrix(5);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result.size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
