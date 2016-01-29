#include <iostream>

using namespace std;

/*The trick is that n = -2147483648,
-n is also -2147483648. If I directly
call myPow(x, -n), it will fall into
infinate recursion.*/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        if (n < 0) {
            n = -n;
            x = 1/x;
        }

        if (n % 2)
            return x*myPow(x*x, n/2);
        else
            return myPow(x*x, n/2);
    }
};

//class Solution {
//public:
//    double myPow(double x, int n) {
//        if(n == 0)
//            return 1;
//        if(n<0){
//            n = -n;
//            x = 1/x;
//        }
//        return (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
//    }
//};

int main() {
    Solution sln = Solution();
    double x = 1.00000;
    int n = -2147483648;
    cout << "pow(" << x << ", " << n << ") = " << sln.myPow(x, n) << endl;
}
