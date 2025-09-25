#include <iostream>
#include <vector>


// https://neetcode.io/problems/find-target-in-rotated-sorted-array?list=neetcode150

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = 0;
        while (l <= r){
            m = (l+r)/2;
            if (nums[m] == target) return m;
            if (target >= nums[l]){
                if (nums[m] > target) r = m;
                else if (nums[m] >= nums[l]) l = m;
                else r = m;
                }
            else {
                if (nums[m] < target) l = m;
                else if  (nums[m] >= nums[l]) l = m;
                else r = m;
            }
        }
        return -1;
    }
};


int main() {
    vector<int> input = {1,3};
    int target = 3;
    Solution s;
    s.search(input, target);
}