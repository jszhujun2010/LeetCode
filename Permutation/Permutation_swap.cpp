#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute_help(result, nums, 0);
        return result;
    }

    void permute_help(vector<vector<int>>& result, vector<int> nums, int i) {
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int j = 0; j <= i; j++) {
            swap(i, j, nums);
            permute_help(result, nums, i+1);
            swap(i, j, nums);
        }
    }

    void swap(int i, int j, vector<int>& nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void print(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++)
            cout << nums[i] << " ";
        cout << endl;
    }
};


int main() {
    vector<int> nums = {1, 2, 3};
    Solution sln = Solution();
    vector<vector<int>> result = sln.permute(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

