#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*The important thing to note is that:
at any time, number of '(' should not
be larger than ')'.
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateP(n, n, result, "");
        return result;
    }

    void generateP(int left, int right, vector<string> &result, string str) {
        if (left > right)
            return;
        if (left > 0)
            generateP(left-1, right, result, str+'(');
        if (right > 0)
            generateP(left, right-1, result, str+')');

        if (left == 0 && right == 0) {
            result.push_back(str);
            return;
        }
    }
};


int main() {
    Solution sln = Solution();
    vector<string> result = sln.generateParenthesis(6);

    for (auto it : result)
        cout << it << endl;
}
