#include <iostream>
#include <vector>

using namespace std;

/*time exceeds*/
//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int n = gas.size();
//
//        int i;
//        for (i = 0; i < n; i++) {
//            int cnt = 0;
//            int left = 0;
//            while (cnt < n) {
//                if (i == n)
//                    i = 0;
//                int index = (i+cnt)%n;
//                left += gas[index]-cost[index];
//                if (left < 0)
//                    break;
//                cnt++;
//            }
//            if (left >= 0)
//                break;
//        }
//        return left >= 0 ? i: -1;
//    }
//};


/*The idea is greedy, and it is sure that the answer is unique.*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int gasSum = 0;
        int costSum = 0;
        int left = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            gasSum += gas[i];
            costSum += cost[i];

            left += gas[i]-cost[i];

            if (left < 0) {
                start = i+1;
                left = 0;
            }
        }

        return gasSum-costSum >= 0 ? start: -1;
    }
};


int main() {
    Solution sln = Solution();
    vector<int> gas = {1, 60, 40};
    vector<int> cost = {70, 10, 1};

    cout << sln.canCompleteCircuit(gas, cost) << endl;
}
