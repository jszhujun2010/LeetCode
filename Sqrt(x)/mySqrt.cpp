#include <iostream>

using namespace std;

//class Solution {
//public:
//    int mySqrt(int x) {
//        if (x <= 1) return x;
//
//        int l = 1, r = x;
//
//        while (l < r) {
//            int mid = l+(r-l)/2;
//            if (x/mid >= mid)
//                l = mid+1;
//            else
//                r = mid;
//        }
//        return l-1;
//    }
//};

/*Newton's method*/
class Solution {
public:
    int mySqrt(int x) {
        int res = x;
        while (res*res > x) {
            res = (res+x/res)/2; //always >= sqrt(x)
        }
        return res;
    }
};


int main() {
    Solution sln = Solution();
    cout << sln.mySqrt(2) << endl;
}
