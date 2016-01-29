#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int n = nums.size();
//        if (n < 1) return -1;
//        int l = 0;
//        int r = n-1;
//
//        return search_cross(nums, target, l, r);
//
//    }
//
//    int search_cross(vector<int>& nums, int target, int l, int r) {
//        int mid = (l+r)/2;
//        if (nums[mid] == target)
//            return mid;
//        if (l == r)
//            return -1;
//
//        if (nums[mid] < nums[l]) {
//            if (nums[mid] < target) {
//                int x = BS(nums, target, mid+1, r);
//                int y = search_cross(nums, target, l, mid);
//                if (x != -1) return x;
//                else if (y != -1) return y;
//                else return -1;
//            }
//            else {
//                return search_cross(nums, target, l, mid);
//            }
//        }
//        else {
//            if (nums[mid] < target) {
//                return search_cross(nums, target, mid+1, r);
//            }
//            else {
//                int a = BS(nums, target, l, mid);
//                int b = search_cross(nums, target, mid+1, r);
//                if (a != -1) return a;
//                else if (b != -1) return b;
//                else return -1;
//            }
//        }
//    }
//
//    int BS(vector<int>& nums, int target, int l, int r) {
//        int mid;
//        while (l < r) {
//            int mid = (l+r)/2;
//            if (nums[mid] == target)
//                return mid;
//            if (nums[mid] < target) {
//                l = mid+1;
//            }
//            else {
//                r = mid;
//            }
//        }
//        return nums[l] == target ? l: -1;
//    }
//};



//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int n = nums.size();
//        if (n < 1) return -1;
//        int l = 0;
//        int r = n-1;
//        int mid;
//
//        while (l < r) {
//            mid = (l+r)/2;
//            if (nums[mid] == target) return mid;
//            if (nums[mid] < nums[l]) {
//                if (nums[mid] < target && target <= nums[r]) l = mid+1;
//                else r = mid-1;
//            }
//            else {
//                if (nums[mid] > target && target >= nums[l]) r = mid-1;
//                else l = mid+1;
//            }
//        }
//
//        return nums[l] == target ? l: -1;
//    }
//
//
//};







/*If there is any duplictes, the only tricky part is:
[3, 1, 2, 3, 3, 3, 3],
nums[mid] = nums[left],
we just skip it. So the worst case, O(n), with all elemnents the same, not the target one*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 1) return -1;
        int l = 0;
        int r = n-1;
        int mid;

        while (l < r) {
            mid = (l+r)/2;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[l]) {
                if (nums[mid] < target && target <= nums[r]) l = mid+1;
                else r = mid-1;
            }
            else if (nums[mid] > nums[l]) {
                if (nums[mid] > target && target >= nums[l]) r = mid-1;
                else l = mid+1;
            }
            else l++;
        }

        return nums[l] == target ? true: false;
    }
};




int main() {
    Solution sln = Solution();
    vector<int> nums = {3, 1, 2, 3, 3, 3, 3};
    for (int i = 0; i < nums.size(); i++)
        cout << sln.search(nums, nums[i]) << endl;
//    cout << sln.search(nums, 6) << endl;
    return 0;
}
