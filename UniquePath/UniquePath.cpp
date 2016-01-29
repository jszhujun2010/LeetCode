#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        int s = m+n-2;
        int t = min(m-1, n-1);
        for (int i = 1; i <= t; i++) {
            result *= s--;
            result /= i;
        }
        return int(result);
    }
};

int main() {
    Solution sln = Solution();
    cout << sln.uniquePaths(51, 9) << endl;
}
