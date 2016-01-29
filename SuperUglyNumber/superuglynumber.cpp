#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> res(n, 0);
        vector<int> index(m, 0);

        res[0] = 1;

        for (int i = 1; i < n; i++) {
            res[i] = INT_MAX;
            for (int j = 0; j < m; j++)
                res[i] = min(res[i], primes[j]*res[index[j]]);
            for (int j = 0; j < m; j++)
                index[j] += (res[i] == primes[j]*res[index[j]]);
        }

        return res[n-1];
    }
};

int main() {
    vector<int> primes = {2, 7, 13, 19};
    Solution sln = Solution();
    cout << sln.nthSuperUglyNumber(12, primes) << endl;
}
