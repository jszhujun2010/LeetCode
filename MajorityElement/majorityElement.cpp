#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*vote algorithm*/
//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        int cnt = 0, n = nums.size(), major;
//        for (int i = 0; i < n; i++) {
//            if (cnt == 0) {
//                cnt++;
//                major = nums[i];
//                continue;
//            }
//            if (nums[i] == major) cnt++;
//            else cnt--;
//        }
//        return major;
//    }
//};

/*bit operation*/
//class Solution {
//public:
//    int majorityElement(vector<int>& nums) {
//        int major = 0, n = nums.size();
//
//        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
//            int bitCount = 0;
//            for (int j = 0; j < nums.size(); j++) {
//                if (nums[j]&mask) bitCount++;
//                if (bitCount > n/2) {
//                    major |= mask; //more consideration
//                    break;
//                }
//            }
//        }
//        return major;
//    }
//};

/*divide and conqure*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return findMajority(nums, 0, nums.size()-1);
    }

    int findMajority(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int mid = l+(r-l)/2;
        int lm = findMajority(nums, l, mid);
        int rm = findMajority(nums, mid+1, r);

        if (lm == rm) return lm;

        return count(nums.begin()+l, nums.begin()+r+1, lm) > count(nums.begin()+l, nums.begin()+r+1, rm) ? lm: rm;
    }
};

int main() {
    Solution sln = Solution();
    vector<int> nums = {6,5,5};
    cout << sln.majorityElement(nums) << endl;
}


