#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
//        vector<int> states(n, 0);
//        for (int j = 1; j <= n; j++) {
//            for (int k = j-1; k < n; k += j) {
//                states[k] = !states[k];
//            }
//        }
//        return accumulate(states.begin(), states.end(), 0);
    }
};

int main() {
    Solution sln = Solution();
    cout << sln.bulbSwitch(10) << endl;
    return 0;
}
