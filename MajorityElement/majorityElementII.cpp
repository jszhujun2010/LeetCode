#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*vote algorithm*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.size() < 1) return res;

        int cnt1 = 0, cnt2 = 0,
            n = nums.size(), major1 = 0, major2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == major1) cnt1++;
            else if (nums[i] == major2) cnt2++;
            else if (cnt1 == 0) {
                cnt1++;
                major1 = nums[i];
            }
            else if (cnt2 == 0) {
                cnt2++;
                major2 = nums[i];
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        /*candidate re-count...*/
        cnt1 = 0;
        cnt2 = 0;
        for (int i: nums) {
            if (i == major1)
                cnt1++;
            if (i == major2)
                cnt2++;
        }

        if (cnt1 > n/3) res.push_back(major1);
        if (cnt2 > n/3 && major2 != major1) res.push_back(major2);
        return res;
    }
};

int main() {
    Solution sln = Solution();
    vector<int> nums = {0};
    vector<int> res = sln.majorityElement(nums);
    for (int x: res)
        cout << x << " ";
    cout << endl;
}

