#include <iostream>
#include <stdlib.h>
using namespace std;

int intcomp(int *x, int *y)
{
    return *x - *y;
}

int main()
{
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    int *x, *y;
    qsort(a,10,sizeof(int),intcomp);
    for(int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
