#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL)
            return 0;
        else
        {
            string current;
            bool flag = false;
            char last = *s;
            while (*s != '\0')
            {
                if(*s == '\0')
                    break;
                if (*s != ' ')
                {
                    if (last == ' ')
                        current.clear();
                    current += *s;
                }
                last = *s++;
            }
            return current.length();
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLastWord("a") << endl;
    return 0;
}
