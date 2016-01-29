#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;

        int n = nums.size();
        if (n < 1) return res;

        vector<bool> used(n, false);

        sort(nums.begin(), nums.end());
        help(nums, cur, res, used);

        return res;
    }

    void help(vector<int> nums, vector<int> cur, vector<vector<int>>& res, vector<bool> used) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        int last = INT_MIN;
        for (int j = 0; j < nums.size(); j++) {
            if (!used[j] && last != nums[j]) {
                used[j] = true;
                cur.push_back(nums[j]);
                help(nums, cur, res, used);

                used[j] = false;
                cur.pop_back();
                last = nums[j];
            }
        }
    }
};

int main() {
    Solution sln = Solution();
    vector<int> nums = {3,3,0,0,2,3,2};
    vector<vector<int>> res = sln.permuteUnique(nums);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
