#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> combinationSum3(int k, int n) {
//        vector<vector<int>> result;
//        vector<int> tmp;
//        combine(1, k, n, 0, result, tmp);
//
//        return result;
//    }
//
//    void combine(int i, int k, int n, int sum, vector<vector<int>> &result, vector<int> tmp) {
//        if (i == 10 || tmp.size() == k || sum >= n) {
//            if (sum == n && tmp.size() == k) {
//                result.push_back(tmp);
//            }
//            return;
//        }
//
//        tmp.push_back(i);
//        combine(i+1, k, n, sum+i, result, tmp);
//
//        tmp.pop_back();
//        combine(i+1, k, n, sum, result, tmp);
//    }
//};

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> tmp;
        combine(1, k, n, result, tmp);

        return result;
    }

    void combine(int i, int k, int target, vector<vector<int>> &result, vector<int> tmp) {
        if (target == 0 && k == 0) {
            result.push_back(tmp);
            return;
        }

        for (int j = i; j < 10; j++) {
            tmp.push_back(j);
            combine(j+1, k-1, target-j, result, tmp);
            tmp.pop_back();
        }
    }
};

int main() {
    Solution sln = Solution();
    vector<vector<int>> result = sln.combinationSum3(3, 9);

    int m = result.size();
    if (m < 1) return 0;
    int n = result[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << " " << endl;
    }
    return 0;
}
