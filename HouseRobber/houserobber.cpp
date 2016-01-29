#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 1) return 0;
        vector<int> dp(sz);
        dp[0] = nums[0];
        if (sz > 1)
            dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < sz; i++)
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        return dp[sz-1];
    }
};

int main() {
    vector<int> nums = {2, 1, 1, 1};
    Solution sln = Solution();
    cout << sln.rob(nums) << endl;
}
