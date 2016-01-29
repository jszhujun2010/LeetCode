#include <iostream>
#include <string>
#include <cstring>
#include <vector>
//#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
       		return "1";
       	else
       	{
       		string prev = countAndSay(n-1);
       		char num_char[8096];        //the length of char array may overflow
       		vector<int> item;
       		vector<int> freq;
       		strcpy(num_char, prev.c_str());
       		int ahead;
       		for (int i = 0; i < prev.length(); ++i)
       		{
       			int temp = int(num_char[i]) - 48;
       			if (i != 0)
                {
                    if (ahead == temp)
                        (*(freq.end()-1))++;
                    else
                    {
                       item.push_back(temp);
                       freq.push_back(1);
                       ahead =  temp;
                    }
                }
       			else
                {
                    item.push_back(temp);
                    freq.push_back(1);
                    ahead =  temp;
                }
       		}
       		if (freq.size() != item.size())
                return "wrong!";
       		string result;
       		for (int i = 0; i < item.size(); i++)
       		{
       			result.append(int_to_string(freq[i]));
       			result.append(int_to_string(item[i]));
       		}
       		return result;
       	}
    }

    string int_to_string(int num)
    {
        std::ostringstream ostr;
        ostr << num;
        return ostr.str();
    }

};

int main()
{
    Solution solution;
    string result = solution.countAndSay(28);
    cout << "result = " << result << endl;
    cout << "result.length() = " << result.length() << endl;
    /*for (int i = 1; i <= 31; i++)
    {
        string result = solution.countAndSay(i);
        cout << "result(" << i << ")= " << result << endl;
    }*/
}
