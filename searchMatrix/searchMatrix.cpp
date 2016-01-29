#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()-1;
        int mid, row;

        if ((r < 0) || (matrix[0].size() < 1) || (target < matrix[l][l]) || (target > matrix[r].back()))
            return false;

        while (l <= r) {

            mid = l + (r-l)/2;
            if (matrix[mid][0] == target)
                return true;
            if (matrix[mid][0] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        //row = l - 1;
        row = r;

/*        if (l > mid)
            row = mid;
        else
            row = r;
*/

        l = 0;
        r = matrix[0].size()-1;

        while (l <= r) {
            mid = l + (r-l)/2;

            if (matrix[row][mid] == target)
                return true;

            if (matrix[row][mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
};


int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 25, 30, 34},
                                  {37, 38, 45, 50}};
//    vector<vector<int>> matrix = {{1}};
    Solution sln = Solution();
    for (int i = 0; i < 60; i++)
        cout << i << ": " << sln.searchMatrix(matrix, i) << endl;
}
