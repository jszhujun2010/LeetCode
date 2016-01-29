#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*This method comes from wikipedia, construction of gray code*/
    vector<int> grayCode(int n) {
        if (n == 0)
            return {0};
        vector<int> result;
        result.push_back(0);
        result.push_back(1);
        int m = 1;
        while(m++ < n)
        {
            vector<int> headhalf(result);
            vector<int> tailhalf(result);
            reverse(tailhalf.begin(), tailhalf.end());
            for (auto &x: tailhalf)
                x += (1 << (m-1));
            headhalf.insert(headhalf.end(), tailhalf.begin(), tailhalf.end());
            result = headhalf;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> result = solution.grayCode(0);
    for (auto &x: result)
        cout << x << endl;
    return 0;
}
