#include <vector>
#include <iostream>

/*actually the same problem as find unique in twos*/

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i] ^ (i+1);
        }
        return result;
    }
};

int main() {
    Solution sln = Solution();
    vector<int> nums = {0, 2, 3};
    cout << sln.missingNumber(nums) << endl;
}
