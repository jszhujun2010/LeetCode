#include <iostream>

#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000

using namespace std;

class Solution {
public:
    int atoi(const char *str)
    {
        long long result = 0;
        int flag = -1;
        while (*str == ' ')
        {
            str++;
            continue;
        }
        if (*str == '+')
            flag = 1;
        else if (*str == '-')
            flag = 0;
        else if ((int(*str)- 48) > 9 || (int(*str)- 48) < 0)
            return 0;
        else
            result = (int(*str)- 48);
        while(*(++str) != '\0')
        {
            int temp = int(*str)- 48;
            if (temp > 9 || temp < 0)
                break;
            result = result*10 + temp;
            if (result > INT_MAX)
            {
                if (flag == 1 || flag == -1 )
                    return INT_MAX;
                else if(result - INT_MAX > 1)
                    return INT_MIN;
            }
        }
        if (flag == 1 || flag == -1)
            return int(result);
        else
            return int(-result);
    }
};

int main()
{
    Solution solution;
    cout << solution.atoi("  2147483648") << endl;
}
