#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = 0;
        int maxEndingHere = 0;
        int maxNum = 0x80000000;
        for (int i = 0; i < nums.size(); i++) {
            maxNum = max(maxNum, nums[i]);
            maxEndingHere = max(maxEndingHere+nums[i], 0);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        if (maxNum >= 0)
            return maxSoFar;
        else
            return maxNum;
    }
};

int main() {
    vector<int> Array = {-2, -3, -1, -5};
    Solution sln = Solution();
    cout << sln.maxSubArray(Array) << endl;
}
