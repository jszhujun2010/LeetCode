#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if (numRows <= 0)
            return {};
        else if (numRows == 1)
            return {{1}};
        else
        {
            vector<vector<int> > prev_vec = generate(numRows-1);
            vector<int> prev,cur;
            prev = prev_vec.back();
            cur.push_back(1);
            for (vector<int>::iterator it = prev.begin(); it != prev.end()-1; it++)
            {
                cur.push_back((*it)+(*(it+1)));
            }
            cur.push_back(1);
            prev_vec.push_back(cur);
            return prev_vec;
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > result;
    result = solution.generate(5);
    for (vector<vector<int> >::iterator out = result.begin(); out != result.end(); out++)
    {
        for (vector<int>::iterator in = (*out).begin(); in != (*out).end(); in++)
        {
            cout << *in << " ";
        }
        cout << '\n' << endl;
    }
    return 0;
}
