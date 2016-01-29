#include <iostream>
#define INT_MAX 0x7fffffff

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int temp = x;
        long long pali = 0;
        while (x >= 10)
        {
            pali = pali*10 + x%10;
            x = x / 10;
        }
        pali = pali*10 + x;
        if (pali > INT_MAX)
            return false;
        else
            return pali == temp;
    }
};

int main()
{
    Solution solution;
    cout << solution.isPalindrome(1001) << endl;
    return 0;
}
