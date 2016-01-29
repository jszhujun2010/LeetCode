#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n < 1) return 0;

        vector<int> mask(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                mask[i] |= 1 << (words[i][j]-'a');
            }
        }

        int max_len = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (mask[i] & mask[j])
                    continue;
                else {
                    int tmp_len = words[i].size()*words[j].size();
                    if (tmp_len > max_len)
                        max_len = tmp_len;
                }
            }
        }

        return max_len;
    }
};

int main() {
    Solution sln = Solution();
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};

    cout << sln.maxProduct(words) << endl;
    return 0;
}
