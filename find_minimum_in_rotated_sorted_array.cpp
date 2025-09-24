#include <iostream>
#include <vector>

// https://neetcode.io/problems/find-minimum-in-rotated-sorted-array?list=neetcode150

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int result = 0;
        int l = 0;
        int r = nums.size()-1;
        int m = 0;
        if (nums[l] < nums[r]) return nums[l];
        while (l < r-1){
            m = (l + r)/2;
            if (nums[l] > nums[m]) r = m;
            else l = m;
        }
        nums[l] < nums[r] ? result = nums[l] : result = nums[r];
        return result;
    }
};


int main() {
    vector<int> input = {4,5,6,7};
    Solution s;
    s.findMin(input);
}