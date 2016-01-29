#include <iostream>
#include <string>

/*Maybe some invalid string cannot be detected*/

using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        if (s.empty())
            return 0;
        else if (s.length() == 1)
            return singleQtoI(*(s.begin()));
        auto head = s.begin();
        auto next = head + 1;
        int cnt = 0;
        bool flag = 0;
        int result = 0;
        while (next != s.end())
        {
            int p = singleQtoI(*head);
            int q = singleQtoI(*next);
            if (p < q && cnt >= 1)
                return 0;
            if (*head != *next)
                cnt = 0;
            else
                cnt++;
            if (cnt > 3)
                return 0;
            else
            {
                if (!flag)
                {
                    if (p >= q)
                        result += p;
                    else
                        flag = true;
                }
                else
                {
                    if (p < q)
                        return 0;
                    else
                    {
                        result += (p-singleQtoI(*(head-1)));
                        flag = false;
                    }
                }
            }
            head++;
            next++;
        }
        if (flag)
            return result+singleQtoI(*head)-singleQtoI(*(head-1));
        else
            return result+singleQtoI(*head);
    }

    int singleQtoI(char c)
    {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.romanToInt("MMMCMXCIX") << endl;
    return 0;
}
