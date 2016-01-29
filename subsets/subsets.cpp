#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> subsets(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> result;
//        for (int i = 0; i <= nums.size(); i++) {
//            vector<int> tmp;
//            help(nums, tmp, result, i, 0);
//        }
//        return result;
//    }
//
//    void help(vector<int> nums, vector<int> tmp, vector<vector<int>>& res, int k, int i) {
//        if (tmp.size() == k) {
//            res.push_back(tmp);
//            return;
//        }
//
//        if (i >= nums.size())
//            return;
//
//        tmp.push_back(nums[i]);
//        help(nums, tmp, res, k, i+1);
//        tmp.pop_back();
//        help(nums, tmp, res, k, i+1);
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> subsets(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> result;
//        vector<int> tmp;
//        help(nums, tmp, result, 0);
//        return result;
//    }
//
//    void help(vector<int> nums, vector<int> tmp, vector<vector<int>>& res, int i) {
//        res.push_back(tmp);
//
//        /*did not find the logic behind it*/
//        for (int j = i; j < nums.size(); j++) {
//            tmp.push_back(nums[j]);
//            help(nums, tmp, res, j+1);
//            tmp.pop_back();
//        }
//    }
//};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = {{}};

        for (int i = 0; i < nums.size(); i++) {
            int size = result.size();
            for (int j = 0; j < size; j++) {
                vector<int> tmp = result[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {4, 1, 0};
    Solution sln = Solution();
    vector<vector<int>> result = sln.subsets(nums);
    int k = result.size();
    int l;
    if (k < 1) l = 0;
    else l = result[0].size();
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
