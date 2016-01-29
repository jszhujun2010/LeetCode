#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = 0;
        bool flag;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                flag = swap(nums, i, red);
                if (flag)
                    i--;
                red++;
            }
            else if (nums[i] == 2) {
                flag = swap(nums, nums.size()-blue-1, i);
                if (flag)
                    i--;
                blue++;
            }
            for (auto i: nums)
                cout << " " << i;
            cout <<" red: " << red << " blue:" << blue << endl;
        }
    }

    bool swap(vector<int>& nums, int i, int j) {
        if (i > j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            return true;
        }
        return false;
    }
};

int main() {
    vector<int> x = {2, 1, 0, 1, 2, 0, 0, 2, 1, 0};
    Solution sln = Solution();
    sln.sortColors(x);
    for (auto i: x)
        cout << " " << i << endl;
    return 0;
}
