#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int m = matrix.size();
//        if (m < 1) return false;
//        int n = matrix[0].size();
//        if (target > matrix[m][n]) return false;
//        if (target < matrix[0][0]) return false;
//
//        int up = 0;
//        int low = 0;
//        vector<int> tmp;
//
//        while (up < n && low < m) {
//            tmp.clear();
//            for (int i = 0; i < m; i++)
//                tmp.push_back(matrix[i][up]);
//            low = basic_BS(tmp, target);
//            if (matrix[low][up] == target)
//                return true;
//
//            low--;
//            tmp.clear();
//            for (int i = 0; i < n; i++)
//                tmp.push_back(matrix[low][i]);
//            up = basic_BS(tmp, target);
//            if (matrix[low][up] == target)
//                return true;
//        }
//
//        return false;
//    }
//
//    int basic_BS(vector<int>& arr, int t) {
//        int l = 0;
//        int r = arr.size();
//
//        while(l < r) {
//            int mid = (l+r)/2;
//            if (arr[mid] >= t) {
//                r = mid;
//            }
//            else
//                l = mid + 1;
//        }
//
//        return l;
//    }
//};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m < 1) return false;
        int n = matrix[0].size();
        if (target > matrix[m-1][n-1]) return false;
        if (target < matrix[0][0]) return false;

        int i = 0;
        int j = n-1;

        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                j--;
            if (matrix[i][j] < target)
                i++;
        }

        return false;
    }
};

int main() {
    Solution sln = Solution();
    vector<vector<int>> matrix;
    matrix.push_back({1, 4,  7, 11, 15});
    matrix.push_back({2, 5,  8, 12, 19});
    matrix.push_back({3, 6,  9, 16, 22});
    matrix.push_back({10, 13, 14, 17, 24});
    matrix.push_back({18, 21, 23, 26, 30});

    cout << sln.searchMatrix(matrix, 500) << endl;
}
