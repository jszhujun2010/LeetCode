#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (A = NULL)
            return 0;
        else
        {
            int i = 0;
            int num = n;
            cout << A[1] << endl;
            while (i < num-1)
            {
                if (A[i] != A[i+1])
                {
                    i++;
                }
                else
                {
                    int bp = num-2;
                    while (bp > i)
                    {
                        A[bp] = A[bp+1];
                        bp--;
                    }
                    num--;
                }
            }
            return num;
        }
    }
};

int main()
{
    int A[5] = {1,1,2,3,3};
    Solution solution;
    int x = solution.removeDuplicates(A, 5);
    cout << "x = " << x << endl;
    for (int i = 0; i < x; i++)
        cout << A[i] << endl;
    return 0;
}
