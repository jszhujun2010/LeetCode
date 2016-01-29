#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*log_n solution*/
//class Solution {
//public:
//    int minSubArrayLen(int s, vector<int>& nums) {
//        int n = nums.size();
//
//        int start = 0, ends = 0, sum = 0, res = INT_MAX;
//        while (ends < n) {
//            while (sum < s && ends < n) sum += nums[ends++];
//
//            if (sum < s) break;
//
//            while (sum >= s && start <= ends) sum -= nums[start++];
//            res = min(res, ends-start+1);
//        }
//        return res == INT_MAX ? 0: res;
//    }
//};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;

        vector<int> sums(n+1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i-1] + nums[i-1];
        }

        for (int i = 0; i < n; i++) {
            vector<int>::iterator up = lower_bound(sums.begin()+i+1, sums.end(), sums[i]+s);

            if (up == sums.end())
                break;
            else {
                res = min(res, up-sums.begin()-i);
            }
        }

        return res == INT_MAX ? 0: res;
    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    Solution sln = Solution();
    cout << sln.minSubArrayLen(7, nums) << endl;

    return 0;
}
