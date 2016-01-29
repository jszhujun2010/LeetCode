#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m < 1) return 0;
        int n = obstacleGrid[0].size();

        vector<vector<int>> res(obstacleGrid);
        if (obstacleGrid[0][0] == 1) return 0;

        res[0][0] = 1;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                res[i][0] = 0;
            else
                res[i][0] = res[i-1][0];
        }

        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 1)
                res[0][i] = 0;
            else
                res[0][i] = res[0][i-1];
        }

        for (int j = 1; j < m; j++) {
            for (int k = 1; k < n; k++) {
                if (obstacleGrid[j][k] == 1)
                    res[j][k] = 0;
                else
                    res[j][k] = res[j-1][k]+res[j][k-1];
            }
        }

        return res[m-1][n-1];

    }
};

int main() {
    Solution sln = Solution();
    vector<vector<int>> obstacleGrid;
    vector<int> vec1 = {0,1,0};
    vector<int> vec2 = {0,1,0};
    vector<int> vec3 = {0,0,0};
    obstacleGrid.push_back(vec1);
    obstacleGrid.push_back(vec2);
    obstacleGrid.push_back(vec3);
    cout << sln.uniquePathsWithObstacles(obstacleGrid) << endl;
}
