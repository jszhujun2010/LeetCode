#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
		vector<vector<string> > result;
        //vector<string> current;
        for (int i = 0; i < s.length(); i++)
        {
            char last = s[i];
            stringstream ss;
            ss << last;
            string cs;
            ss >> cs;
            if (i == 0)
            {
                vector<string> first;
                first.push_back(cs);
                result.push_back(first);
            }
            else
            {
				vector<vector<string> > result_copy;
                for (auto it = result.begin(); it != result.end(); it++)
                {
					vector<string> current = *it;
					vector<string> temp = current;
					temp.push_back(cs);
					//(*it).push_back(s);
					result_copy.push_back(temp);
                    vector<string> candi;
                    string backstring;
                    bool flag = false;
					auto inner = current.rbegin();
					if ((*inner).length() == 1 && (*inner)[0] == last)
					{
						backstring = cs + cs;
						candi = current;
						candi.back() = backstring;
						result_copy.push_back(candi);
					}
					if (++inner != current.rend())
					{
						if ((*inner).length() == 1 && (*inner)[0] == last)
						{
							backstring = last + current.back() + last;
							candi = current;
							candi.pop_back();
							candi.back() = backstring;
							result_copy.push_back(candi);
						}
					}
                }
				result = result_copy;
            }
        }
		//vector<vector <string>> final(result.begin(), result.end());
        return result;
    }
};

int main()
{
    string s = "seeslaveidemonstrateyetartsnomedievalsees";
    Solution solution;
    vector<vector <string>> result = solution.partition(s);
    for (auto outer = result.begin(); outer != result.end(); outer++)
    {
        for (auto inner = (*outer).begin(); inner != (*outer).end(); inner++)
        {
            cout << *inner << " ";
        }
        cout << endl;
    }
	/*cout << result.size() << endl;*/
    return 0;
}
