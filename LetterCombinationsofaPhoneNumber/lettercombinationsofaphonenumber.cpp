#include <iostream>
#include <vector>
#include <map>

using namespace std;

//class Solution {
//public:
//    vector<string> letterCombinations(string digits) {
//        vector<string> res;
//        string cur;
//
//        if (digits.size() < 1)
//            return res;
//
//        map<char, string> dict;
//        dict['2'] = "abc";
//        dict['3'] = "def";
//        dict['4'] = "ghi";
//        dict['5'] = "jkl";
//        dict['6'] = "mno";
//        dict['7'] = "pqrs";
//        dict['8'] = "tuv";
//        dict['9'] = "wxyz";
//
//        help(0, dict, res, cur, digits);
//
//        return res;
//    }
//
//    void help(int i, map<char, string> dict, vector<string>& res, string cur, string digits) {
//        if (i == digits.size()) {
//            res.push_back(cur);
//            return;
//        }
//
//        for (int k = 0; k < dict[digits[i]].size(); k++) {
//            cur.push_back(dict[digits[i]][k]);
//            help(i+1, dict, res, cur, digits);
//            cur.pop_back();
//        }
//    }
//};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits.size() < 1)
            return res;

        map<char, string> dict;
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";

        /*use a data structure as a queue*/
        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            char x = digits[i];
            while (res.front().size() == i) {
                string cur = res[0];
                res.erase(res.begin());

                for (char c: dict[digits[i]]) {
                    res.push_back(cur+c);
                }
            }
        }

        return res;
    }
};


int main() {
    Solution sln = Solution();
    string s = "23";
    vector<string> res = sln.letterCombinations(s);

    for (string s: res)
        cout << s << " ";
    cout << endl;
}
