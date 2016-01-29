#include <iostream>
#include <vector>

using namespace std;

/*This is just like one-dimension curve,
can be simplified as four cases:
1. keep decreasing
2. keep increasing
3. first increasing, then decreasing
4. first decreasing, then increasing*/

/*binary search, key idea:
two step,
1. find the one larger than the right one
2. find the one larger than the left one */

/*two mistakes made(or basicly one):
1. status of last (change with related variable)
2. what is exactly the last we want? the piviot one!!!
*/

/*others' idea, its a general binary search:
find some elem such that local max,
max condition: nums[i-1] < nums[i] > nums[i+1].
if now nums[mid] < nums[mid+1],  it is an incerasing area,
to find max, we need shift to right;
otherwise, we need to shift to left;
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*corner case*/
        if (nums.size() < 1)
            return -1;

        if (nums.size() == 1)
            return 0;

        if (nums.size() == 2) {
            if (nums[0] > nums[1])
                return 0;
            else
                return 1;
        }

//        bool flag = false;
        int i = 1;
        int last, temp;

        /*base case*/
        if (nums[0] > nums[1])
            return 0;

        while (i < nums.size()-1) {
            if (nums[i] < nums[i+1]) {
                last = i;
                i = (i + nums.size())/2;
            }
            else {
                if (nums[i] < nums[i-1]) {
                    i = (last + i)/2;
                }
                else
                    return i;
            }
        }
        return i;
    }
};

class Another {
public:
    int findMax(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        int mid;
        while(left < right) {
            mid = left + (right-left)/2;
            if (nums[mid] < nums[mid+1]) {
                left = mid + 1;
            }
            else
                right = mid;
        }
        return left;
    }
};

int main() {
    Another an = Another();
//    Solution sln = Solution();
//    vector<int> data = {1, 2, 3, 4, 5, 6};
//    vector<int> data = {1, 2, 3, 4, 3, 6};
//    vector<int> data = {6, 7, 4, 3, 2, 1};
//    vector<int> data = {3, 2, 1, 2, 3, 4};
//    vector<int> data = {-9986,-9952,-9941,-9918,-9869,-9858,-9854,-9847,-9828,-9782,-9765,-9740,-9719,-9671,-9667,-9580,-9552,-9536,-9520,-9515,-9513,-9461,-9412,-9411,-9405,-9352,-9323,-9307,-9303,-9264,-9253,-9245,-9209,-9196,-9182,-9157,-9103,-9076,-9014,-8906,-8897,-8871,-8851,-8811,-8804,-8722,-8643,-8593,-8552,-8529,-8498,-8485,-8465,-8426,-8394,-8375,-8362,-8333,-8328,-8325,-8310,-8309,-8308,-8279,-8261,-8237,-8180,-8177,-8159,-8157,-8140,-8138,-8130,-8116,-7957,-7927,-7889,-7887,-7877,-7867,-7843,-7765,-7754,-7690,-7669,-7642,-7638,-7609,-7598,-7576,-7560,-7537,-7454,-7438,-7434,-7354,-7334,-7300,-7269,-7234,-7201,-7198,-7146,-7137,-7124,-7081,-7056,-7047,-6950,-6931,-6900,-6891,-6883,-6826,-6814,-6762,-6658,-6648,-6606,-6583,-6514,-6494,-6476,-6447,-6418,-6415,-6371,-6311,-6283,-6245,-6234,-6172,-6141,-6118,-6105,-6055,-6022,-5982,-5955,-5933,-5925,-5908,-5881,-5875,-5697,-5672,-5655,-5653,-5616,-5541,-5420,-5415,-5403,-5394,-5381,-5319,-5307,-5281,-5256,-5239,-5197,-5151,-5086,-5034,-5018,-4888,-4830,-4815,-4812,-4782,-4761,-4733,-4731,-4716,-4678,-4656,-4647,-4625,-4580,-4564,-4562,-4531,-4516,-4451,-4423,-4421,-4332,-4312,-4284,-4278,-4267,-4264,-4257,-4249,-4227,-4218,-4194,-4179,-4168,-4167,-4155,-4109,-4096,-4059,-4008,-3899,-3881,-3874,-3864,-3848,-3807,-3798,-3793,-3777,-3737,-3731,-3719,-3675,-3667,-3662,-3576,-3502,-3467,-3440,-3422,-3410,-3393,-3289,-3232,-3112,-3074,-2942,-2892,-2875,-2870,-2852,-2840,-2752,-2725,-2704,-2703,-2690,-2636,-2629,-2625,-2553,-2520,-2486,-2483,-2470,-2457,-2421,-2406,-2396,-2393,-2391,-2369,-2243,-2226,-2156,-2149,-2140,-2134,-2133,-2116,-2108,-2094,-2089,-2066,-2065,-2046,-2021,-2002,-1890,-1878,-1861,-1851,-1808,-1790,-1767,-1765,-1732,-1601,-1585,-1531,-1529,-1476,-1474,-1465,-1359,-1326,-1323,-1229,-1168,-1138,-1131,-1061,-1029,-1018,-1004,-849,-755,-745,-742,-715,-704,-690,-671,-666,-593,-545,-514,-468,-424,-369,-265,-249,-230,-211,-208,-188,-172,-146,-114,-106,-89,-47,-42,-30,5,18,44,205,303,357,363,365,379,427,469,485,540,558,582,591,598,681,707,729,730,732,759,771,789,812,888,941,1019,1027,1034,1121,1128,1142,1160,1165,1178,1181,1197,1268,1270,1314,1403,1412,1424,1451,1464,1478,1483,1512,1553,1565,1573,1602,1649,1751,1767,1778,1793,1802,1808,1815,1852,1898,1924,1930,1960,1965,1974,2059,2061,2096,2212,2219,2285,2329,2352,2360,2387,2390,2444,2453,2485,2499,2533,2551,2573,2578,2642,2665,2674,2715,2721,2843,2846,2857,2859,2893,2907,2935,2963,2970,3018,3034,3061,3072,3075,3096,3127,3148,3156,3201,3219,3252,3257,3286,3291,3312,3381,3386,3430,3522,3573,3575,3619,3687,3753,3763,3766,3767,3780,3811,3822,3910,3922,3923,3927,3933,3954,3999,4013,4014,4016,4034,4047,4085,4133,4174,4192,4208,4211,4257,4278,4308,4339,4365,4375,4414,4433,4443,4499,4501,4574,4632,4643,4754,4761,4771,4780,4815,4850,4866,4879,4888,4889,4909,4981,5003,5004,5026,5061,5079,5101,5105,5132,5255,5273,5335,5337,5345,5355,5384,5396,5455,5464,5472,5533,5566,5570,5649,5692,5699,5719,5908,5926,5939,5988,5990,6058,6087,6160,6182,6188,6199,6207,6218,6224,6278,6280,6350,6357,6406,6416,6533,6563,6579,6596,6628,6643,6690,6697,6713,6756,6805,6816,6865,6890,6953,7025,7037,7057,7063,7175,7214,7230,7293,7301,7317,7334,7344,7455,7515,7540,7544,7598,7617,7624,7630,7654,7688,7707,7738,7743,7750,7792,7857,7909,7931,7943,7982,7992,8044,8051,8086,8159,8186,8213,8218,8229,8247,8252,8278,8311,8314,8359,8379,8438,8460,8523,8558,8564,8587,8604,8646,8678,8715,8741,8772,8792,8827,8853,8899,8934,8979,8995,9000,9037,9053,9064,9085,9095,9123,9184,9206,9247,9253,9282,9339,9386,9397,9410,9441,9537,9548,9572,9580,9584,9593,9629,9637,9681,9716,9726,9746,9763,9788,9873,9893,9910,9975,9991,9974,9948,9786,9754,9665,9498,9384,9345,9341,9211,9129,9048,9023,8789,8275,8273,8249,8210,8196,8190,8107,8093,8077,7917,7872,7858,7675,7509,7481,7468,7392,7375,7308,7304,7284,7204,7095,7035,7018,6966,6771,6711,6479,6393,6367,6247,6245,6180,5869,5820,5778,5770,5681,5666,5655,5654,5608,5600,5584,5583,5524,5393,5343,5298,5226,5100,5064,4946,4870,4859,4831,4741,4568,4478,4476,4340,4272,4218,4215,4181,4172,4116,4032,3882,3831,3799,3697,3668,3665,3614,3477,3318,3288,3234,3221,3137,3098,3063,3040,3033,2999,2694,2693,2595,2583,2550,2459,2335,2287,2270,2259,2258,2138,2126,2056,1992,1981,1958,1926,1873,1776,1687,1669,1665,1522,1514,1497,1488,1482,1395,1384,1209,1064,983,955,814,697,692,584,566,480,433,429,376,374,254,226,141,126,101,27,16,-50,-225,-302,-407,-453,-462,-464,-470,-480,-513,-775,-866,-870,-892,-930,-1053,-1114,-1141,-1158,-1182,-1265,-1266,-1290,-1291,-1297,-1470,-1472,-1546,-1562,-1657,-1719,-1752,-1848,-1867,-1999,-2000,-2018,-2139,-2274,-2318,-2350,-2437,-2447,-2456,-2518,-2519,-2533,-2542,-2547,-2552,-2686,-2770,-2800,-2804,-2932,-2953,-3116,-3149,-3188,-3221,-3292,-3395,-3430,-3481,-3485,-3491,-3532,-3568,-3592,-3679,-3718,-3766,-3771,-3788,-3820,-3933,-3988,-4019,-4040,-4062,-4136,-4243,-4271,-4294,-4437,-4450,-4509,-4569,-4570,-4593,-4732,-4773,-4823,-5105,-5132,-5170,-5171,-5173,-5179,-5255,-5359,-5461,-5533,-5552,-5558,-5615,-5693,-5711,-5750,-5812,-5954,-6126,-6146,-6154,-6162,-6183,-6262,-6304,-6360,-6644,-6692,-6786,-6795,-6810,-6844,-6920,-6928,-6994,-7001,-7020,-7060,-7304,-7315,-7368,-7399,-7616,-7720,-7833,-7835,-7862,-7890,-7891,-7995,-8014,-8099,-8170,-8178,-8222,-8244,-8384,-8451,-8706,-8776,-8797,-8831,-8885,-8888,-8918,-8937,-8944,-8950,-8976,-8981,-9087,-9185,-9225,-9248,-9418,-9517,-9650,-9714,-9724,-9773,-9821,-9827,-9880,-9889,-9901};
    vector<int> data = {1, 2, 3, 2, 1};
    //cout << sln.findPeakElement(data) << endl;
    cout << an.findMax(data) << endl;
}
