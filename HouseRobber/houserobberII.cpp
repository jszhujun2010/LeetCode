#include <iostream>
#include <vector>

using namespace std;

/*there is another elegent way:
two-pass: (0, n-2) and (1, n-1)
take the max*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        vector<bool> head(sz, true);
        bool tail = false;
        if (sz < 1) return 0;
        vector<int> dp(sz);
        dp[0] = nums[0];
        head[0] = true;
        if (sz > 1) {
            if (nums[0] <= nums[1]) {
                dp[1] = nums[1];
            }
            else {
                dp[1] = nums[0];
                head[1] = true;
            }
        }
        for (int i = 2; i < sz-1; i++) {
            if (dp[i-2] + nums[i] < dp[i-1]) {
                dp[i] = dp[i-1];
                head[i] = head[i-1];
            }
            else {
                dp[i] = dp[i-2] + nums[i];
                head[i] = head[i-2];
            }
        }
        if (sz > 2) {
            if (dp[sz-3] + nums[sz-1] < dp[sz-2]) {
                dp[sz-1] = dp[sz-2];
                head[sz-1] = head[sz-2];
            }
            else {
                dp[sz-1] = dp[sz-3] + nums[sz-1];
                head[sz-1] = head[sz-3];
                tail = true;
            }
        }
        if (!(head[sz-1] && tail))
            return dp[sz-1];
        else {
            int tmp = dp[sz-2];
            dp[0] = 0;
            if (sz > 1)
                dp[1] = nums[1];
            for (int i = 2; i < sz; i++)
                dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            return max(dp[sz-1], tmp);
        }
    }
};

int main() {
    vector<int> nums = {2, 1, 0, 1};
    Solution sln = Solution();
    cout << sln.rob(nums) << endl;
}

