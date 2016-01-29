#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int>> result;
//        vector<int> tmp;
//
//        help(n, k, 1, result, tmp);
//        return result;
//    }
//
//    void help(int n, int k, int i, vector<vector<int>> &result, vector<int> tmp) {
//        if (tmp.size() == k) {
//            result.push_back(tmp);
//            return;
//        }
//
//        if (i > n)
//            return;
//
//        tmp.push_back(i);
//        help(n, k, i+1, result, tmp);
//
//        tmp.pop_back();
//        help(n, k, i+1, result, tmp);
//    }
//};


/*The idea behind here is that:
for example, [1,2,3,4], k=3
we can only count from 1 or 2(all elem in order),
in the second turn, we just add combination of
(i+1, n).
The concept of range here(a little heuristic) means
the start up number should be limited in a range(otherwise,
 there will be nothing qualified.)*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        combine(1,n,k,ans,temp); //call fuction to get combination of k numbers which range is 1-n
        return ans;
    }
private:
       void combine(int begin,int n, int k, vector<vector<int>> &ans, vector<int>& temp){
            if(k==0){
                ans.push_back(temp);
                return;
            }
            //condition : n-i+1 is the range, range must greater than k
            for(int i=begin;n-i+1>=k;i++){ // for the ith iteration, get the combination of i and k-1 numbers differ from i.
                temp.push_back(i);
                combine(i+1,n,k-1,ans,temp);// get the combination of k-1 numbers which range is(i+1,n)
                temp.pop_back();
            }
        }
};

int main() {
    Solution sln = Solution();
    int n = 4;
    int k = 3;
    vector<vector<int>> result = sln.combine(n, k);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
