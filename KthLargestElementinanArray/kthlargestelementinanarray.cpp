#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        return select(0, nums.size()-1, nums.size()-k, nums);
//    }
//
//    int select(int left, int right, int k, vector<int>& nums) {
//        if (left == right)
//            return nums[left];
//
//        int index = partition_bi(nums, left, right, left);
//
////        cout << left << right << index << endl;
//
//        if (index == k)
//            return nums[k];
//
//        if (index > k)
//            return select(left, index-1, k, nums);
//        else
//            return select(index+1, right, k, nums);
//    }
//
//    int partition_bi(vector<int>& nums, int l, int u, int p) {
//        /*for random trick*/
//        swap(nums, l, p);
//        p = l;
//        u++;
//        while (true) {
//            do {l++;} while(l <= u && nums[l] < nums[p]);
//            do {u--;} while(nums[u] > nums[p]);
//
//            if (u < l) break;
//
//            swap(nums, l, u);
//        }
//        swap(nums, p, u);
//
//        return u;
//    }
//
//    /*This function implements two side partition to save time
//    for unnecessary calculation.*/
//    int partition_bi(vector<int>& nums) {
//        int l = 0;
//        int u = nums.size();
//        int p = l;
//
//        while (true) {
//            /*This is really brilliant!!!
//            Since l start from left and skip 0, we have to check the right bound.
//            While u in the worst case may come across 0, we do not have to check.*/
//            do {l++;} while(l <= u && nums[l] < nums[p]);
//            do {u--;} while(nums[u] > nums[p]);
//
//            if (l > u)
//                break;
//
//            swap(nums, l, u);
//        }
//
//        swap(nums, p, u);
//
//        return u;
//    }
//
//    /*This function implements piviot as first elements*/
//    /*return piviot, change nums*/
//    int partition(vector<int>& nums) {
//        int l = 0;
//        int u = nums.size();
//        int p = l;
//
//        /*The invariant is that: nums[l+1 ~ p] < nums[l] and nums[p+1 ~ i-1] >= nums[l]
//        In each loop, we just swap nums[p+1](the first bigger elem) with nums[i] if
//        nums[i] < nums[l] to keep the invariant.
//        However, there are some special cases, if the l+1, l+2 element are smaller
//        than nums[l], what is the case? That is to say, we now get nothing bigger than
//        nums[l], we just swap with ourselves...*/
//        for (int i = l+1; i < u; i++) {
//            if (nums[i] < nums[l]) {
//                swap(nums, i, ++p);
//            }
//        }
//        swap(nums, p, l);
//        return p;
//    }
//
//    void swap(vector<int>& nums, int i, int j) {
//        if (i == j) return;
//        int tmp = nums[i];
//        nums[i] = nums[j];
//        nums[j] = tmp;
//    }
//};


/*This solution is a iterative version of quick selection*/
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        int left = 0, right = nums.size();
//
//        while (left < right) {
//            int i = left, j = right-1, piviot = left;
//            /*if i cross j, i.e i==j, then :
//            1. i = i+1, stop; j stop
//            2. j = j-1, stop; i stop.
//            So, they must be different. We should make sure
//            that j points to the last one larger than piviot value.*/
//            while (i <= j) {
//                while (i <= j && nums[i] >= nums[piviot]) i++;
//                while (i <= j && nums[j] < nums[piviot]) j--;
//
//                if (i < j) swap(nums[i++], nums[j--]);
//            }
//            swap(nums[piviot], nums[j]);
//
//            if (j == k-1) return nums[j];
//            if (j > k-1) right = j;
//            else left = j+1;
//        }
//
//        return -1;
//    }
//};

/*This solution is a iterative version of quick selection*/
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        priority_queue<int> pq(nums.begin(), nums.end());
//        for (int i = 0; i < k-1; i++)
//            pq.pop();
//        return pq.top();
//    }
//};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> ms;
        for (int i = 0; i < nums.size(); i++) {
            ms.insert(nums[i]);
            if (ms.size() > k)
                ms.erase(ms.begin());
        }
        return *ms.begin();
    }
};

int main() {
    Solution sln = Solution();
    vector<int> nums = {5,2,7,1,6,3,4};
//    int p = sln.partition_bi(nums, 0, nums.size(), 0);
//    for (int n: nums)
//        cout << n << " ";
//    cout << endl;
//    cout << p << endl;
//    for (int i = 1; i <= nums.size(); i++)
//        cout << sln.findKthLargest(nums, i) << endl;

    cout << sln.findKthLargest(nums, 5) << endl;
}
