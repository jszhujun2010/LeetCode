#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int numSquares(int n) {
//
//        vector<int> squareSet;
//        int i = 1;
//        while(i*i <= n) {
//            squareSet.push_back(i*i);
//        i++;
//        }
//
//        vector<int> tmp;
//        int result = n;
//        getResult(n, result, tmp, squareSet);
//
//        return result;
//    }
//
//    void getResult(int target, int& result, vector<int> tmp, vector<int> squareSet) {
//        if (target <= 0) {
//            if (target == 0) {
//                if (tmp.size() < result)
//                    result = tmp.size();
//            }
//            return;
//        }
//
//        if (tmp.size() > result)
//            return;
//
//        for (int j = 0; j < squareSet.size(); j++) {
//            tmp.push_back(squareSet[j]);
//            getResult(target-squareSet[j], result, tmp, squareSet);
//            tmp.pop_back();
//        }
//    }
//};


/*Really a piece of shit!!! Not necessary to set a two-dimensional array.
It's pointless. Actually, we should think from sub-problem.*/
//class Solution {
//public:
//    int numSquares(int n) {
//
//        vector<int> squareSet;
//        int i = 1;
//        while(i*i <= n) {
//            squareSet.push_back(i*i);
//            i++;
//        }
//
//        vector<vector<int>> dp;
//        vector<int> zeros(squareSet.size(), 0);
//        for (int i = 0; i <= n; i++) {
//            dp.push_back(zeros);
//        }
//
//        for (int i = 0; i <= n; i++)
//            dp[i][0] = i;
//
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j < squareSet.size(); j++) {
//                if (i-squareSet[j] >= 0) {
//                    /*This logic is not clear in my mind*/
//                    if (dp[i-squareSet[j]][j]+1 < dp[i-squareSet[j]][j-1])
//                        dp[i-squareSet[j]][j] = dp[i-squareSet[j]][j]+1;
//                }
//            }
//        }
//
//        return dp[n][squareSet.size()-1];
//    }
//};

/*What is the sub-problem? dp[i] = min(dp[i-j*j]+1) for all j*j < i*/

class Solution {
public:
    int numSquares(int n) {

        vector<int> dp(n+1, 0);

        for (int i = 1; i <=n; i++) {

            int tmp = i;
            for (int j = 1; j*j <= i; j++) {
                tmp = min(tmp, dp[i-j*j]+1);
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};

int main() {
    Solution sln = Solution();
    for (int i = 0; i <= 80; i++)
        cout << i << " " << sln.numSquares(i) << endl;
//    cout << sln.numSquares(4) << endl;
}
