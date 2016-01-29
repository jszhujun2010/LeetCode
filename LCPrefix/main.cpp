#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        //string str = (*it);
        //auto ch = str.begin();
        int index = 0;
        bool flag = 0;
        string result = "";
        char cur;
        if (strs.empty())
            return "";
        else if (strs.size() == 1)
            return strs[0];
        while (true)
        {
            string prev,forwd;
            for (vector<string>::iterator it = strs.begin(); it != strs.end()-1; it++)
            {
                prev = *it;
                forwd = *(it+1);
                if ((prev.length()*forwd.length() == 0) || (index > max(prev.length(), forwd.length())-1) || (prev[index] != forwd[index]))
                {
                    flag = 1;
                    break;
                }
                cur = prev[index];
            }
            if (flag)
                return result;
            else
            {
                result.append(1,cur);
                index++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"a"};
    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}
