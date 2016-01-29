#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combine(0, candidates, target, tmp, result);

        return result;
    }

    void combine(int i, vector<int> candidates, int target, vector<int> tmp, vector<vector<int>>& result) {
        if (target <= 0) {
            if (target == 0)
                result.push_back(tmp);
            return;
        }

        int last = INT_MIN;
        for (int j = i; j < candidates.size(); j++) {
            if (candidates[j] != last) {
                tmp.push_back(candidates[j]);
                combine(j+1, candidates, target-candidates[j], tmp, result);

                last = candidates[j];
                tmp.pop_back();
            }
        }
    }

};

int main() {
    Solution sln = Solution();
    vector<int> candi = {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,
                        12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,
                        27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,
                        28,11,33,10,32,22,13,34,18,12};
    vector<vector<int>> result = sln.combinationSum2(candi, 27);

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
