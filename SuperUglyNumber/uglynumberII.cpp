#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    bool isUgly(int num) {
//        int last = num+1;
//        bool cond = (num == 1);
//        while (num != last) {
//            last = num;
//            if (!(num % 2) && !cond) num /= 2;
//            if (!(num % 3) && !cond) num /= 3;
//            if (!(num % 5) && !cond) num /= 5;
//        }
//        if (num == 1)
//            return true;
//        else
//            return false;
//    }
//};

/*actually another dp thinking, from 1 to n.*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> result(n);
        result[0] = 1;
        int two = 0, three = 0, five = 0;
        for (int i = 1; i < n; i++) {
            if (result[two]*2 <= result[three]*3 && result[two]*2 <= result[five]*5) {
                result[i] = result[two]*2;
                if (result[two]*2 == result[three]*3) three++;
                if (result[two]*2 == result[five]*5) five++;
                two++;
            }
            else if (result[three]*3 <= result[two]*2 && result[three]*3 <= result[five]*5) {
                result[i] = result[three]*3;
                if (result[three]*3 == result[two]*2) two++;
                if (result[three]*3 == result[five]*5) five++;
                three++;
            }
            else {
                result[i] = result[five]*5;
                if (result[five]*5 == result[two]*2) two++;
                if (result[five]*5 == result[three]*3) three++;
                five++;
            }
        }
        return result[n-1];
    }
};

int main() {
    Solution sln = Solution();
    cout << sln.nthUglyNumber(19) << endl;
}


