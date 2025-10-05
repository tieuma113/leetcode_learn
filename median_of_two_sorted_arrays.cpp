#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// https://neetcode.io/problems/median-of-two-sorted-arrays?list=neetcode150

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m+n+1)/2;

        int lo = max(0, totalLeft-n);
        int hi = min(totalLeft, m);

        while (lo <= hi){
            int i = (lo + hi) /2;
            int j = totalLeft - i;
            int Aleft = (i > 0) ? nums1[i - 1] : INT_MIN;
            int Aright = (i < m) ? nums1[i] : INT_MAX;
            int Bleft = (j > 0) ? nums2[j -1] : INT_MIN;
            int Bright = (j < n) ? nums2[j] : INT_MAX;

            if ((Aleft <= Bright) && (Aright >= Bleft)) {
                if ((m + n) % 2){
                    return (double) max(Aleft, Bleft);
                }else {
                    return (max(Aleft, Bleft) + (double)min(Aright, Bright))/2.0;
                }
            } else if (Aleft > Bright) {
                hi = i - 1;
            } else {
                lo = i + 1;
            }
        }
        return 0.0;
    }
};

int main(){

}