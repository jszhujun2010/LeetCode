#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0)
            return {};
        else if (rowIndex == 0)
            return {1};
        else if (rowIndex == 1)
        return {1,1};
        else
            {
                int i = 1;
                vector<int> prev;
                vector<int> cur = {1};
                while (i <= rowIndex)
                {
                    prev = cur;
                    cur.clear();
                    cur.push_back(1);
                    for (vector<int>::iterator it = prev.begin(); it != prev.end()-1; it++)
                    {
                        //cout << *(it)+*(it+1) << endl;
                        cur.push_back((*(it)+*(it+1)));
                    }
                    cur.push_back(1);
                    i++;
                }
                return cur;
            }
    }
};

int main()
{
    Solution solution;
    vector<int> result = solution.getRow(3);
    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << endl;
    return 0;
}
