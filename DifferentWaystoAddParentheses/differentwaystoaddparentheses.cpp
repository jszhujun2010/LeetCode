#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*what do I miss here? I know this can be handeled through
divide and conquer method, but my mind is restricted to
(compound)op(single) and (single)op(compound), hope to
find a recursive way to solve it. But what is the return value?
It is hard to implement!!!*/

/*another thing is that not every number is supposed to be
less than 10.*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        vector<int> left;
        vector<int> right;

        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                string a = input.substr(0, i);
                string b = input.substr(i+1, input.size()-i-1);

                left = diffWaysToCompute(a);
                right = diffWaysToCompute(b);

                for (int k = 0; k < left.size(); k++)
                    for (int l = 0; l < right.size(); l++)
                        result.push_back(calc(left[k], right[l], input[i]));
                }
        }

        if (result.size() == 0) {
            int n = 0;
            for (int j = 0; j < input.size(); j++)
                n = 10*n + (input[j]-'0');
            result.push_back(n);
        }

        return result;
    }


    int calc(int a, int b, char c) {
        if (c == '+')
            return a+b;
        else if (c == '-')
            return a-b;
        else
            return a*b;
    }
};

int main() {
    Solution sln = Solution();
    string input = "2*3-4*5";

    vector<int> result = sln.diffWaysToCompute(input);

    for (int i: result)
        cout << i << " ";
    cout << endl;
}
