#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums): nums(nums) {
        len = nums.size();
        vector<bool> temp1(len, false);
        used = temp1;
        vector<int> temp2(len);
        cur = temp2;
    }

    void permute(int i) {
        if(i == len) {
            result.push_back(cur);
            return;
        }

        int last = -1;
        for (int j = 0; j < len; j++) {
            if (!used[j] && last != nums[j]) {
                last = nums[j];
                used[j] = true;
                cur[i] = nums[j];
                permute(i+1);
                used[j] = false;
            }
        }
    }

    void print() {
        for (int i = 0; i < cur.size(); i++)
            cout << cur[i] << " ";
        cout << endl;
    }

    vector<vector<int>> getResult() {
        return result;
    }

private:
    int len;
    vector<bool> used;
    vector<int> cur;
    vector<vector<int>> result;
    vector<int> nums;
};


int main() {
    vector<int> nums = {3, 1, 3};
    Solution sln = Solution(nums);
    sln.permute(0);
    vector<vector<int>> result = sln.getResult();

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
