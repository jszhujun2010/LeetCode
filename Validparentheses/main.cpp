#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
            return true;
        else if (s.length()%2)
            return false;
        vector<char> symbol;
        symbol.push_back(s[0]);
        for (auto i = s.begin()+1; i != s.end(); i++)
        {
            char top = *(symbol.end()-1);
            if (isMatch(*i, top) || isMatch(top, *i))
                symbol.pop_back();
            else
                symbol.push_back(*i);
        }
        if (symbol.empty())
            return true;
        else
            return false;
    }
    bool isMatch(char a, char b)
    {
        if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
            return true;
        else
            return false;
    }
};

int main()
{
    Solution solution;
    cout << solution.isValid("[(])") << endl;
    return 0;
}
