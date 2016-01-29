#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int n = nums.size();
//        vector<bool> canjump(n-1, false);
//        canjump[0] = true;
//        int max_far, last_far=0;
//        for (int i = 0; i < n-1; i++) {
//            if (canjump[i]) {
//                max_far = i+nums[i];
//                if (max_far > last_far) {
//                    while (last_far < max_far) {
//                        canjump[++last_far] = true;
//                    }
//                }
//            }
//        }
//        return canjump[n-1];
//    }
//};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;
        int max_far = 0;
        for (int i = 0; i < n-1; i++) {
            if (i > max_far)
                return false;
            else
            {
                max_far = max(max_far, i+nums[i]);
                if (max_far >= n-1)
                    return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution sln = Solution();
    cout << sln.canJump(nums) << endl;
}
