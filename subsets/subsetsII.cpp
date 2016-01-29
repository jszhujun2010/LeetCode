#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        vector<int> tmp;
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end());
//        help(0, nums, tmp, result);
//        return result;
//    }
//
//    void help(int i, vector<int>& nums, vector<int> tmp, vector<vector<int>>& result) {
//        result.push_back(tmp);
//
//        int last = INT_MIN;
//        for (int j = i; j < nums.size(); j++) {
//            if (last == nums[j]) continue;
//            tmp.push_back(nums[j]);
//            help(j+1, nums, tmp, result);
//            tmp.pop_back();
//            last = nums[j];
//        }
//    }
//};

/*iterative version
The idea is that we can only insert duplicate elem after
newly inserted elem.*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        sort(nums.begin(), nums.end());

        int size = 0;
        for (int i = 0; i < nums.size(); i++) {
            int si = (i > 0 && nums[i] == nums[i-1]) ? size: 0;
            size = result.size();
            for (int j = si; j < size; j++) {
                vector<int> tmp = result[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};
    Solution sln = Solution();
    vector<vector<int>> result = sln.subsetsWithDup(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
