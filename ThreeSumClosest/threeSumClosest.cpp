#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*cheated!!!*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 3)
            return accumulate(nums.begin(), nums.end(), 0);

        sort(nums.begin(), nums.end());

        int i, j ,k, res = nums[0]+nums[1]+nums[2], cur;
        for (i = 0; i < n-2; i++) {
            j = i + 1;
            k = n-1;

            while (j < k) {
                cur = nums[i]+nums[j]+nums[k];
                if (abs(res-target) > abs(cur-target))
                    res = cur;
                if (res == target)
                    return res;

                cur > target ? k--: j++;
            }
        }

        return res;
    }
};

int main() {
    //to do
    Solution sln = Solution();
    vector<int> nums = {1,1,1,1};
    int target = 0;

    cout << sln.threeSumClosest(nums, target) << endl;

    return 0;
}
