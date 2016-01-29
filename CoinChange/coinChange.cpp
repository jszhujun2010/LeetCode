#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> cur(amount+1, -1);
        cur[0] = 0;

        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= amount; i++) {
                if (i-coins[j-1] >= 0 && cur[i-coins[j-1]] != -1)
                    /*I forgot the min operation*/
                    cur[i] = cur[i] < 0 ? cur[i-coins[j-1]]+1: min(cur[i], cur[i-coins[j-1]]+1);
            }
        }

        return cur[amount];
    }
};

int main() {
    vector<int> coins = {370,417,408,156,143,434,168,83,177,280,117};
    Solution sln = Solution();

    cout << sln.coinChange(coins, 9953) << endl;

    return 0;
}
