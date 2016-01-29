#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxSubArray(vector<int> List)
    {
        int maxsofar = 0;
        int maxendinghere = 0;
        for (int i = 0; i < List.size(); i++)
        {
            maxendinghere = max(maxendinghere+List[i], 0);
            maxsofar = max(maxsofar, maxendinghere);
        }
        return maxsofar;
//        vector<int> dp;
//        if (List[0] > 0)
//            dp.push_back(Lis
                           t[0]);
//        else
//            dp.push_back(0);
//        int Max = 0;
//        for (int i = 1; i < List.size(); i++)
//        {
//            if (List[i] < 0)
//            {
//                if (List[i]+dp[i-1] < 0)
//                {
//                    Max = dp[i-1];
//                    dp.push_back(0);
//                }
//                else
//                {
//                    dp.push_back(List[i]+dp[i-1]);
//                }
//            }
//            else
//            {
//                dp.push_back(List[i]+dp[i-1]);
//                if (List[i]+dp[i-1] > Max)
//                    Max = List[i] + dp[i-1];
//            }
//        }
//        return Max;
    }
};

int main()
{
    vector<int> List = {-1,2,3,-4,5,6,0,-1,2,4,-9,10,-200,20,-10,2,3,4};
    Solution solution;
    cout << solution.maxSubArray(List) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
