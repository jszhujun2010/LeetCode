#include <iostream>
#include <vector>

using namespace std;

/*remember the standard style of upper bound and lower bound*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid = (r-l)/2+l;
        bool found = false;
        vector<int> res;

        while (l < r) {
            mid = (r-l)/2+l;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }

        if (nums[l] == target)
            found = true;

        if (!found) {
            res = {-1, -1};
            return res;
        }

        int left = l, right;
        r = nums.size()-1;
        while (true) {
            mid = (r-l)/2+l;
            if (nums[mid] == nums[left]) {
                if (mid == nums.size()-1) {
                    right = nums.size()-1;
                    break;
                }
                else if (nums[mid] < nums[mid+1]) {
                    right = mid;
                    break;
                }
                else {
                    l = mid+1;
                }
            }
            else {
                r = mid - 1;
            }
        }
        res = {left, right};
        return res;
    }
};

//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int l = 0;
//        int r = nums.size()-1;
//        int mid = (r-l)/2+l;            //must initilize
//        vector<int> res(2, -1);
//
//        while (l < r) {
//            mid = (r-l)/2+l;
//            if (nums[mid] < target) l = mid + 1;
//            else r = mid;
//        }
//
//        if (nums[l] == target) res[0] = l;      //be careful the bug here... what is the index we should compare?
//        else return res;
//
//
//        l = 0;
//        r = nums.size()-1;
//        while (l < r) {
//            mid = (r-l)/2+l+1;
//            if (nums[mid] > target) r = mid - 1;
//            else l = mid;
//        }
//
//        res[1] = r;
//        return res;
//    }
//};

int main() {
    Solution sln = Solution();
    vector<int> nums = {1};
    vector<int> res = sln.searchRange(nums, 1);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
