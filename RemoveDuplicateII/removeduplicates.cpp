#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int n = nums.size(), count = 0;
//        for (int i = 2; i < n; i++) {
//            if (nums[i] == nums[i - 2 - count]) count++;
//            else nums[i - count] = nums[i];
//        }
//
//        return n - count;
//    }
//};


/*two pointers: i and n,
i points to the third duplicate elem(if any), or moves with n;
n points to the most current elem.
One thing is important: it is sorted.
We just move at most two duplicate elems, and then wait for the next larger elem.*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        for (int n: nums) {
            if (i < 2 || n > nums[i-2]) {
                nums[i++] = n;
            }
        }

        return i;
    }
};

int main() {
    Solution sln = Solution();
    vector<int> x = {1,1,1,1,2,2,2,2,3,3,3,3};
    int y = sln.removeDuplicates(x);
    cout << y << endl;
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << endl;
}
