#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//
//        int max_len = 1;
//        vector<int> seq;
//        seq.push_back(1);
//        for (int i = 1; i < nums.size(); i++) {
//            int max_cur_len = 1;
//            for (int j = 0; j < i; j++) {
//                if (nums[j] < nums[i] && (seq[j] + 1) > max_cur_len)
//                    max_cur_len = seq[j] + 1;
//            }
//            seq.push_back(max_cur_len);
//            if (max_cur_len > max_len)
//                max_len = max_cur_len;
//        }
//        return max_len;
//    }
//};

//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//
//        vector<int> tmp;
//        for (int i = 0; i < nums.size(); i++) {
//            if (tmp.empty() || nums[i] > tmp[tmp.size()-1]) {
//                tmp.push_back(nums[i]);
//            }
//            else {
//                int found = binarySearch(tmp, 0, tmp.size()-1, nums[i]);
//                tmp[found] = nums[i];
//            }
//        }
//        return tmp.size();
//    }
//
//    int binarySearch(vector<int>& tmp, int left, int right, int target) {
//        int mid = 0;
//        while (left < right) {
//            mid = (left + right)/2;
//            if (tmp[mid] == target)
//                return mid;
//
//            if (tmp[mid] > target)
//                right = mid;
//            else
//                left = mid + 1;
//        }
//
//        return left;
//    }
//};

//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        vector<int> LIS;
//        for (int i = 0; i < nums.size(); i++) {
//            if (LIS.size() == 0 || LIS[LIS.size() - 1] < nums[i]) {
//                LIS.push_back(nums[i]);
//            }
//            else {
//                int l = 0, r = LIS.size() - 1;
//                while (l < r) {
//                    int m = (l + r) / 2;
//                    //key point
//                    if (LIS[m] >= nums[i]) {
//                        r = m;
//                    }
//                    else {
//                        l = m + 1;
//                    }
//                }
//                LIS[l] = nums[i];
//            }
//        }
//        return LIS.size();
//    }
//};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;

        vector<int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            if (tmp.empty() || nums[i] > tmp[tmp.size()-1]) {
                tmp.push_back(nums[i]);
            }
            else {
                int found = binarySearch(tmp, 0, tmp.size()-1, nums[i]);
                tmp[found] = nums[i];
            }
        }
        return tmp.size();
    }

    /*great idea!!!*/
    int binarySearch(vector<int>& tmp, int left, int right, int target) {
        int cnt = right - left;
        int step;
        int first = left;
        while (cnt > 0) {
            first = left;
            step = cnt/2;
            first += step;
            if (tmp[first] < target) {
                left = ++first;
                cnt -= step+1;
            }
            else cnt = step;
        }
        return left;
    }
};

int main() {
    Solution sln = Solution();
    vector<int> nums = {3,5,6,7,12};
//    vector<int> nums = {2,5,6};
    cout << sln.binarySearch(nums, 0, nums.size()-1, 5) << endl;
//    cout << sln.lengthOfLIS(nums) << endl;
}
