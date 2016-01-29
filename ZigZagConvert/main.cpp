#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows)
    {
        if (s.empty())
            return "";
        else if (nRows == 1)        //Be careful of such case!
            return s;
        else
            {
                string result;
                for (int i = 0; i < nRows; i++)
                {
                    unsigned int j = i;
                    if (i == 0 || i == nRows-1)
                    {
                        while (j < s.length())
                        {
                            result += s[j];
                            j += 2*(nRows-1);
                        }
                    }
                    else
                    {
                        int gap1 = 2*(nRows-1-i);
                        int gap2 = 2*i;
                        while (j < s.length())
                        {
                            result += s[j];
                            j += gap1;
                            if (j < s.length())
                            {
                                result += s[j];
                                j += gap2;
                            }
                        }
                    }
                }
                return result;
            }
    }
};

int main()
{
    Solution solution;
     cout << solution.convert("abcdefgh", 1) << endl;
    return 0;
}
