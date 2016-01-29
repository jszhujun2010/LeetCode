#include <iostream>

using namespace std;

/*cheated!!!*/
/*It is very trickly!!!
The idea behind it is that: given a range
[xxxx01xxxx, xxxx11xxxx]
suppose the higher bits are the same, there
must be xxxx10xxxx in the range, so the fifth
bit must be zero. we should find the most left(
count from right) bit that the two numbers(bits left) are
the same.*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            i++;
        }
        return n << i;
    }
};

int main() {
    Solution sln = Solution();
    cout << sln.rangeBitwiseAnd(5, 7) << endl;
}
