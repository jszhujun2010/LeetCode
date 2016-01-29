#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute_help(result, nums);
        return result;
    }

    void permute_help(vector<vector<int>>& result, vector<int> nums) {
        if (nums.size() == 0)
            return;

        if (nums.size() == 1) {
            result.push_back(nums);
            return;
        }

        vector<int> slice(nums.begin()+1, nums.end());
        vector<vector<int>> temp = permute(slice);
        for (int i = 0; i < temp.size(); i++) {
            vector<int> elem = temp[i];
            for (int j = 0; j < nums.size(); j++) {
                vector<int> side;
                for (int k = 0; k < j; k++) {
                    side.push_back(elem[k]);
                }
                side.push_back(nums[0]);;
                for (int k = j; k < elem.size(); k++) {
                    side.push_back(elem[k]);
                }
                result.push_back(side);
            }
        }
        return;
    }
};


int main() {
    vector<int> nums = {1,2};
    Solution sln = Solution();
    vector<vector<int>> result = sln.permute(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
