#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n < 1) return 0;
        if (n == 1) return triangle[0][0];
        int a = triangle[0][0]+triangle[1][0];
        int b = triangle[0][0]+triangle[1][1];
        if (n == 2) return min(a, b);

        vector<int> last(n, 0);
        last[0] = a;
        last[1] = b;
        vector<int> now(n, 0);


        for (int i = 2; i < n; i++) {
            now[0] = last[0]+triangle[i][0];
            now[i] = last[i-1]+triangle[i][i];
            for (int j = 1; j <= i-1; j++) {
                now[j] = min(last[j-1]+triangle[i][j], last[j]+triangle[i][j]);
            }
            last = now;
        }

        return *min_element(now.begin(),now.end());
    }
};

int main() {
    vector<vector<int>> triangle;
    vector<int> t1 = {2};
    vector<int> t2 = {3, 4};
    vector<int> t3 = {6, 5, 7};
    vector<int> t4 = {4, 1, 8, 3};
    triangle.push_back(t1);
    triangle.push_back(t2);
    triangle.push_back(t3);
    triangle.push_back(t4);

    Solution sln = Solution();
    cout << sln.minimumTotal(triangle) << endl;
}
