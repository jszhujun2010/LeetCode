#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0;
        int w = 0;
        for (int b = 0; b < nums.size(); b++) {
            int l = nums[b];
            nums[b] = 2;

            if (l < 2) {
                nums[w] = 1;
                w++;
            }

            if (l == 0) {
                nums[r] = 0;
                r++;
            }
        }
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

