/*This file implements heap/priority queue with vector.
* generic version is later consideration, for now,  only
* int type is considered. */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* This is one thing we should notice:
 * the para of siftup and siftdown:
 * for siftup: we sift the current elem
 * to the top, so para means current
 * elem's index;
 * for siftdown: we sift top elem down,
 * maybe the most later elem is sorted,
 * we do not need all elem in array, just
 * part of it, so the para means the last
 * elem index we want to participate the
 * sift procedure.
 * Maybe they are the same: the last index
 * we want in the array.*/

class heap {
public:
    /*constructor, heapfy an array.
     *this is 1 based array, 0th elem
     *is wasted.*/
    heap(vector<int>& num) {
        nums = num;
        nums.insert(nums.begin(), 0);
        if (nums.size() > 2)
            for (int i = 2; i < nums.size(); i++)
                siftup(i);
    }

    /*sift up last element.
    *remember the pre-cond: heap(1,n-1)
    * post-cond: heap(1, n)*/
    void siftup(int n) {
        int i = n;
        int p;

        while (true) {
            if (i == 1) break;
            p = i/2;
            if (nums[p] <= nums[i]) break;
            swap(nums[i], nums[p]);
            i = p;
        }
    }

    /*sift down first element.
    *remember the pre-cond: heap(2,n)
    * post-cond: heap(1, n)*/
    void siftdown(int n) {
        int i = 1;
        int c;

        while (true) {
            c = 2*i;
            if (c > n) break;

            /*legal case, should take equal*/
            if (c+1 <= n)
                if (nums[c+1] < nums[c])
                    c++;

            if (nums[c] >= nums[i])
                break;

            swap(nums[c], nums[i]);
            i = c;
        }
    }

    void insert(int x) {
        nums.push_back(x);
        siftup(nums.size()-1);
    }

    int extactMin() {
        int n = nums.size()-1;
        if (n < 1)
            return -1;
        int result = nums[1];
        nums[1] = nums[n];
        nums.erase(nums.begin()+n);
        n--;
        siftdown(n);
        return result;
    }

    vector<int> heapSort() {
        //heap(nums);
        for (int i = nums.size()-1; i > 1; i--) {
            swap(nums[i], nums[1]);
            siftdown(i-1);
        }
        nums.erase(nums.begin());
        reverse(nums.begin(), nums.end());
        return nums;
    }

    vector<int> heapInsertSort(vector<int> input) {
        //heap(nums);
        for (int i = 0; i < input.size(); i++) {
            insert(input[i]);
        }

        vector<int> result;
        int round = nums.size();
        for (int i = 0; i < round-1; i++)
            result.push_back(extactMin());

        return result;
    }

private:
    vector<int> nums;
};

int main() {
    vector<int> nums = {5, 2, 7, 1, 6, 3, 4};
    heap h = heap(nums);
    vector<int> result = h.heapSort();
//    vector<int> origin;
//    heap h = heap(origin);
//    vector<int> result = h.heapInsertSort(nums);
    for (int i: result)
        cout << i << " ";
    cout << endl;
    return 0;
}
