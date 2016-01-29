#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        else
        {
            auto head = s.begin();
            auto tail = s.end()-1;
            while (tail - head > 0)
            {
                while(!((*head) >= 48 && (*head) <= 57) && !((*head) >= 65 && (*head) <= 90) && !(((*head) >= 97) && (*head) <= 122) && head != s.end())
                {
                    head++;
                }
                while(!((*tail) >= 48 && (*tail) <= 57) && !((*tail) >= 65 && (*tail) <= 90) && !(((*tail) >= 97) && (*tail) <= 122) && tail != s.begin())
                {
                    tail--;
                }
                //cout << *head << endl;
                //cout << *tail << endl;
                //cout << (*tail)-(*head) << endl;
                if (head >= tail)
                    return true;
                else if ((*head) != (*tail) && ((*head)-(*tail) != 32) && ((*tail)-(*head) != 32))
                    return false;
                else
                    {
                        head++;
                        tail--;
                    }
            }
            return true;
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.isPalindrome("1a2") << endl;
}
