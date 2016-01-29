#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *p = A;
        int *q = B;
        int pos = 0;
        int curlen = m;
        for (int i = 0; i < n; i++)
        {
            while (*p < *q)
            {
                if (pos == curlen)
                    break;
                pos++;
                p++;
            }
            if (pos >= curlen)
            {
                A[pos++] = B[i];
                continue;
            }
            for (int j = curlen; j > pos; j--)
                A[j] = A[j-1];
            A[pos] = *q;
            curlen++;
            q++;
        }
    }
};

int main()
{
    Solution solution;
    int A[6] = {1,3};
    int B[4] = {2,4,5,6};
    solution.merge(A,2,B,4);
    for (int i = 0; i < 6; i++)
        cout << A[i] << endl;
    return 0;
}
