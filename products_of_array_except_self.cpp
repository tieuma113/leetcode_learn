#include <iostream>
#include <vector>

// Products of Array Except Self
// Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

// Each product is guaranteed to fit in a 32-bit integer.

// Follow-up: Could you solve it in O(n) time without using the division operation?

// Example 1:
// Input: nums = [1,2,4,6]
// Output: [48,24,12,8]

// Example 2:
// Input: nums = [-1,0,1,2,3]
// Output: [0,-6,0,0,0]

// Constraints:
// 2 <= nums.length <= 1000
// -20 <= nums[i] <= 20

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i_sz = nums.size();
        vector<int> v_result(i_sz,0);
        for (int i = 0; i < i_sz; i++){
            for (int k = 0; k < i_sz; k++){
                if (i == k) continue;
                v_result[k] *= nums[i];
            }
        }
        return v_result;
    }
};


int main(){

}