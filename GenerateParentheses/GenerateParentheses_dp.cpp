#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
DP solution:
"(" + substring + ")" + substring
*/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > dp(n+1);
        dp[0].push_back("");
        for (int i = 1; i <= n; i++) {
            vector<string> vstr;
            for (int j = 0; j < i; j++) {
                vector<string> left = dp[j];
                vector<string> right = dp[i-j-1];
                for (int k = 0; k < left.size(); k++)
                    for (int l = 0; l < right.size(); l++) {
                        dp[i].push_back("("+left[k]+")"+right[l]);
                }
            }
        }
        return dp.back();
    }
};


int main() {
    Solution sln = Solution();
    vector<string> result = sln.generateParenthesis(3);

    for (auto it : result)
        cout << it << endl;
}
