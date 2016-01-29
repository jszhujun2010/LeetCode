#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        int min_so_far = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min_so_far)
                min_so_far = prices[i];
            if ((prices[i] - min_so_far) > max_profit)
                max_profit = prices[i] - min_so_far;
        }
        return max_profit;
    }
};


int main() {
    vector<int> prices = {5, 4, 3, 2, 1, 7, 10, 5};
    Solution sln = Solution();
    cout << sln.maxProfit(prices) << endl;
}
