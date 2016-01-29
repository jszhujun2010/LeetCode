#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        permute_help(result, nums, temp, 0);
        return result;
    }

    void permute_help(vector<vector<int>>& result, vector<int> nums, vector<int>& temp,  int i) {
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int j = 0; j <= i; j++) {
            temp.insert(temp.begin()+j, nums[i]);
            print(temp);
            permute_help(result, nums, temp, i+1);
            temp.erase(temp.begin()+j);
        }
    }

    void print(vector<int> x) {
        for (auto y: x)
            cout << y << " ";
        cout << endl;
    }
};


int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution sln = Solution();
    vector<vector<int>> result = sln.permute(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

