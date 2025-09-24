#include <iostream>
#include <vector>


// https://neetcode.io/problems/binary-search?list=neetcode150

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;
        while (l < r) {
            int mid = l+((r-l)/2);
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};


int main(){
    vector<int> input = {-1,0,2,4,6,8};
    Solution s;
    s.search(input, 4);
}