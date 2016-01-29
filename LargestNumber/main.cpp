#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    string largestNumber(vector<int> &num) {
//        vector<int> original(num);
//        int decimal = *max_element(num.begin(), num.end());
//        vector<int> max_vector = CalcuLength(decimal);
//        int max_length = max_vector[0];
//        vector<pair<int, int> > Data;
//        int index = 0;
//        for (auto &x: num)
//        {
//            vector<int> temp = CalcuLength(x);
//            int length = temp[0];
//            int last = x%10;
//            int first = temp[1];
//            while (length < max_length)
//            {
//                x = x*10 + max(last, first);
//                length++;
//            }
//            Data.push_back(make_pair(x, index++));
//        }
//        sort(Data.begin(), Data.end());
//
//        string result;
//        int j = Data.back().second;
//        if (original[j] == 0)
//            return "0";
//        int i = 0;
//        for (auto &y: Data)
//        {
//            i = y.second;
//            ostringstream ss;
//            ss << original[i];
//            result.insert(0, ss.str());
//        }
//            //result += to_string(y); //this is well-known bug in MinGW
//        return result;
//    }
//
//    vector<int> CalcuLength(int x)
//    {
//        if (x == 0)
//            return {1, 0};
//        int length = 0;
//        while (x >= 10)
//        {
//            x = x / 10;
//            length++;
//        }
//        return {length+1, x};
//    }
//};

class Solution {
public:
    string largestNumber(vector<int> &num) {

    }

    bool compare(int x, int y)
    {
        vector<int> digit_x = GetDigit(x);
        vector<int> digit_y = GetDigit(y);
        int min_length = min(digit_x.size(), digit_y.size());
        int i = 0;
        while (i < min_length)
        {
            if (digit_x[i] < digit_y[i])
                return true;
            else if (digit_x[i] > digit_y[i])
                return false;
            i++;
        }
        if (digit_x.size() == min_length)
        {
            for (int j = 0; j < min_length; j++)
            {
                if (digit_x[j+1] > digit_y[j])
                    return true;
                else if (digit_x[j+1] < digit_y[j])
                    return false;
            }
        }
    }

    vector<int> GetDigit(int x)
    {
        vector<int> result;
        while(x > 0)
        {
            result.push_back(x%10);
            x = x/10;
        }
        reverse(result);
        return result;
    }
};

int main()
{
    vector<int> num = {3, 30, 34, 5, 9};
    Solution solution;
    cout << solution.largestNumber(num) << endl;
    return 0;
}
