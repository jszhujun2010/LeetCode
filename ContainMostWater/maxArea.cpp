#include <iostream>
#include <vector>

using namespace std;

/**
The trick is that
we start from begin and end.
only if there is some height(between l, r) bigger than
current min(l, r)
can we guess some area in the middle
is larger.
**/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int max_water = 0;
        int l(0), r(len-1), h(0);

        while (l < r) {
            h = min(height[l], height[r]);
            max_water = max(max_water, (r-l)*h);

            while (height[l] <= h && l < r)
                l++;
            while (height[r] <= h && l < r)
                r--;
        }
        return max_water;
    }
};

int main() {
vector<int> height = {3, 2, 4, 2, 1};
Solution sln = Solution();
cout << sln.maxArea(height) << endl;
}
