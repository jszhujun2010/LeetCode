#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        //set<vector<int> > s;
        if (num.size() < 3)
            return result;
        sort(num.begin(), num.end());
        vector<int> candi;
        for (auto it = num.begin()+1; it != num.end()-1;it++)
        {
            int media = *it;
            auto record = num.end() - 1;
            if (!candi.empty())
                if (candi[1] == media)
                {
                    if (candi[0] == candi[1])
                    {
                        while (*it == media && it != num.end())
                            it++;
                        if (--it == num.end()-1)
                            break;
                        else
                            continue;
                    }
                    for (auto x = record; x != it; x--)
                        if (*x + media*2 == 0)
                        {
                            result.push_back({media, media, *x});
                            break;
                        }
                    while (*it == media && it != num.end())
                        it++;
                    if (--it == num.end()-1)
                        break;
                    else
                        continue;
                }
            for (auto left = num.begin(); left != it; left++)
            {
                if (!candi.empty())
                    if (*left == candi[0] && media == candi[1])
                        continue;
                if (media + *left > 0)
                    break;
                if (media + *left + *record < 0)
                    continue;
                for (auto right = record; right != it; right--)
                {
                    if (media + *left + *right == 0)
                    {
                        candi.clear();
                        candi.push_back(*left);
                        candi.push_back(media);
                        candi.push_back(*right);
                        result.push_back(candi);
                        record = right;
                        break;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> input =
    //{-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    //{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    {0, 0, 0, 0};
    //{7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    vector<vector<int> > result = solution.threeSum(input);
    for (auto out = result.begin(); out != result.end(); out++)
    {
        for (auto inner = (*out).begin(); inner != (*out).end(); inner++)
        {
            cout << *inner << " ";
        }
        cout << "next" << endl;
    }
    return 0;
}
