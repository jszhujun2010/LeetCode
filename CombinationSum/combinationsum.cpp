#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combine(0, candidates, target, tmp, result);

        return result;
    }

    void combine(int i, vector<int>& candidates, int target, vector<int> tmp, vector<vector<int>>& result) {
        if (target <= 0) {
            if (target == 0)
                result.push_back(tmp);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            tmp.push_back(candidates[j]);
            combine(j, candidates, target-candidates[j], tmp, result);
            tmp.pop_back();
        }
    }
};

int main() {
    Solution sln = Solution();
    vector<int> candi = {8, 7, 4, 3};
    vector<vector<int>> result = sln.combinationSum(candi, 11);

    int m = result.size();
    if (m < 1) return 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << " " << endl;
    }
    return 0;
}

