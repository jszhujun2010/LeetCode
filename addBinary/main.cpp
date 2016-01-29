#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() || b.empty())
            return "error!";
        else
        {
            string ap(a);
            string bp(b);
            if (a.length() > b.length())
            {
                while (ap.length() > bp.length())
                    bp.insert(0,"0");
            }
            else
            {
                while (ap.length() < bp.length())
                    ap.insert(0,"0");
            }
            auto ita = ap.rbegin();
            auto itb = bp.rbegin();
            string result = "";
            bool addflag = false;
            char elem;
            while (ita != ap.rend() && itb != bp.rend())
            {
                char elem_a = *ita;
                char elem_b = *itb;
                if ((elem_a == '0' && elem_b == '1') || (elem_a == '1' && elem_b == '0'))
                {
                    if (addflag)
                    {
                        result += '0';
                        addflag = true;
                    }
                    else
                        result += '1';
                }
                if (elem_a == '0' && elem_b == '0')
                {
                    if (addflag)
                    {
                        result += '1';
                        addflag = false;
                    }
                    else
                        result += '0';
                }
                if (elem_a == '1' && elem_b == '1')
                {
                    if (addflag)
                        result += '1';
                    else
                    {
                        result += '0';
                        addflag = true;
                    }
                }
                ita++;
                itb++;
            }
            if (addflag)
                result += '1';
            reverse(result.begin(), result.end());
            return result;
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.addBinary("1", "111") << endl;
    return 0;
}
