#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*int reverse(int x) {
        int i = 1;
        int result = 0;
        if (x > 0)
        {
            vector<int> digits = GetDigits(x);
            for (auto iter = digits.rbegin(); iter != digits.rend(); iter++)
            {
                result += (*iter)*i;
                i *= 10;
            }
            return result;
        }
        else
        {
            int temp = -x;
            vector<int> digits = GetDigits(temp);
            for (auto iter = digits.rbegin(); iter != digits.rend(); iter++)
            {
                result += (*iter)*i;
                i *= 10;
            }
            return -result;
        }
    }

    vector<int> GetDigits(int x)
    {
        vector<int> digits;
        while (x >= 10)
        {
            digits.push_back(x%10);
            x = x/10;
        }
        digits.push_back(x);
        return digits;
    }*/

    int reverse(int x) {
        if (x > 0)
        {
            string str = int_to_string(x);
            std::reverse(str.begin(),str.end());
            if (string_to_int(str)  == 0)
                return 0;
            else
                return string_to_int(str);
        }
        else if (x == 0)
            return 0;
        else
        {
            string str = int_to_string(-x);
            std::reverse(str.begin(),str.end());
            if (string_to_int(str)  == 0)
                return 0;
            else
                return -string_to_int(str);
        }
    }

    string int_to_string(int num)
    {
        std::ostringstream ostr;
        ostr << num;
        return ostr.str();
    }

    int string_to_int(string str)
    {
        std::istringstream ss(str);
        unsigned num;
        ss >> num;
        if (num > 0x7fffffff)
            return 0;
        else
            return num;
    }
};


int main()
{
    //cout << int_to_string(1000000003) << endl;
    Solution solution;
    cout << solution.reverse(-1000000002) << endl;
    return 0;
}
