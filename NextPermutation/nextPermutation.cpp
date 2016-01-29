#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**low efficiency**/
//class Solution {
//public:
//    void nextPermutation(vector<int>& nums) {
//        int n = nums.size();
//        if (n <= 1) return;
//
//        int i = n-1;
//
//        while (i > 0) {
//            int j = i-1;
//            int l = i;
//            while (j < n) {
//                if (nums[j] < nums[l])
//                    break;
//                l++;
//            }
//            if (l < n) {
//                swap(nums[l], nums[j]);
//                break;
//            }
//            else {
//                int origin = nums[j];
//                for (int k = j+1; k < n; k++)
//                    nums[k-1] = nums[k];
//                nums[n-1] = origin;
//            }
//            i--;
//        }
//    }
//};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;

        int i = n-1;

        /*find the first nums[i-1] < nums[i] from the last elem*/
        while (i > 0) {
            if (nums[i-1] < nums[i])
                break;
            i--;
        }

        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        /*find the one to swap(first one larger than nums[i-1])*/
        int val = nums[i-1];
        int j = n-1;
        while (nums[j] < val && j >= i-1) {
            j--;
        }

        swap(nums[j], nums[i-1]);

        sort(nums.begin()+i, nums.end());

    }
};

int main() {
    Solution sln = Solution();
    vector<int> nums = {7,1,4,2};

    sln.nextPermutation(nums);

    for (int i: nums)
        cout << i << " ";
    cout << endl;
}
