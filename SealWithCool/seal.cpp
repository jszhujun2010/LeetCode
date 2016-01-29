#include <iostream>
#include <vector>

using namespace std;

/*accroding to state machine:
s0: s0 -> s0, s2 -> s0 (stay cool dowm or from sell) --free state
s1: s0 -> s1, s1 -> s1 (buy or buy then do nothing)  --buy state(wating for sale)
s2: s1 -> s2 (buy then sell)                         --sale state*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 0) return 0;

        /*O(1) space solution*/
        int s0 = 0;
        int s1 = -prices[0];
        int s2 = INT_MIN;

        for (int i = 1; i < n; i++) {
            int tmp = s0;
            s0 = max(s0, s2);
            s1 = max(s1, tmp-prices[i]);
            s2 = s1+prices[i];
        }

        return max(s0, s2);

//        vector<int> s0(n, 0);
//        vector<int> s1(n, 0);
//        vector<int> s2(n, 0);
//
//        s0[0] = 0;
//        s1[0] = -prices[0];
//        s2[0] = INT_MIN;
//
//        for (int i = 1; i < n; i++) {
//            s0[i] = max(s0[i-1], s2[i-1]);
//            s1[i] = max(s1[i-1], s0[i-1]-prices[i]);
//            s2[i] = s1[i-1]+prices[i];
//        }
//        return max(s0[n-1], s2[n-1]);
    }
};

int main() {
    Solution sln = Solution();
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << sln.maxProfit(prices) << endl;
}
