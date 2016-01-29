#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums): nums(nums) {
        len = nums.size();
        vector<int> temp(len);
        cur = temp;

        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            it = num_map.find(nums[i]);
            if (it != num_map.end())
                it->second++;
            else
                num_map[nums[i]] = 1;
        }
    }

    void permute(int i) {
        if(i == len) {
            result.push_back(cur);
            return;
        }

        for (map<int,int>::iterator it=num_map.begin(); it!=num_map.end(); ++it) {
            if (it->second > 0) {
                it->second--;
                cur[i] = it->first;
                permute(i+1);
                it->second++;
            }
        }
    }

    void print() {
        for (int i = 0; i < cur.size(); i++)
            cout << cur[i] << " ";
        cout << endl;
    }

    vector<vector<int>> getResult() {
        return result;
    }

private:
    int len;
    map<int, int> num_map;
    vector<int> cur;
    vector<vector<int>> result;
    vector<int> nums;
};


int main() {
    vector<int> nums = {3, 1, 3, 1};
    Solution sln = Solution(nums);
    sln.permute(0);
    vector<vector<int>> result = sln.getResult();

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
