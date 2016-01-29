#include <iostream>
#include <vector>

using namespace std;

/*accroding to state machine:
s0: s0 -> s0, s2 -> s0 (stay cool dowm or from sell) --free state
s1: s0 -> s1, s1 -> s1 (buy or buy then do nothing or sell then buy)  --buy state(wating for sale)
s2: s1 -> s2 (buy then sell)                         --sale state*/

//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        if (n <= 0) return 0;
//
//        /*O(1) space solution*/
//        int s0 = 0;
//        int s1 = -prices[0];
//        int s2 = 0;
//
//        for (int i = 1; i < n; i++) {
//            int tmp = s0;
//            s0 = max(s0, s2);
//            s1 = max(max(s1, tmp-prices[i]), s2-prices[i]);
//            s2 = s1+prices[i];
//        }
//
//        return max(s0, s2);
//    }
//};

/*This is only something for increasing area*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 0) return 0;

        /*O(1) space solution*/
        int result = 0;
        for (int i = 0; i < n-1; i++) {
            result += max((prices[i+1] - prices[i]), 0);
        }
        return result;
    }
};

int main() {
    Solution sln = Solution();
    vector<int> prices = {1, 4, 2};
    cout << sln.maxProfit(prices) << endl;
}
