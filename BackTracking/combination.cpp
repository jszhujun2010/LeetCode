#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums): nums(nums) {
        len = nums.size();
    }

    /*The reasonable explaination is that:
    in each case, either push the i-th
    element or not, then go to the next
    turn recursion.
    The finish case ia that we have got
    around all the elements, no matter
    it is in our combination or not.
    */

    void combination(int i, vector<int> cur) {
        if (i == len) {
            result.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        combination(i+1, cur);

        cur.pop_back();
        combination(i+1, cur);
    }

    void combination2(int i, vector<int> cur) {
        if (cur.size() > 0)
            result.push_back(cur);

        for (; i < len; i++) {
            cur.push_back(nums[i]);
            combination2(i+1, cur);
            cur.pop_back();
        }
    }

    void combination(int n, int i, vector<int> cur) {
        if (cur.size() == n) {
            result.push_back(cur);
            return;
        }

        if (i == len)
            return;

        cur.push_back(nums[i]);
        combination(n, i+1, cur);
        cur.pop_back();
        combination(n, i+1, cur);
    }

    void print(vector<int> cur) {
        for (int i = 0; i < cur.size(); i++)
            cout << cur[i] << " ";
        cout << endl;
    }

    vector<vector<int>> getResult() {
        return result;
    }

private:
    int len;
    vector<vector<int>> result;
    vector<int> nums;
};


int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution sln = Solution(nums);
    vector<int> cur;
    sln.combination(3, 0, cur);
    vector<vector<int>> result = sln.getResult();

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
