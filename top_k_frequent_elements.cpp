#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

// Top K Frequent Elements

// Given an integer array nums and an integer k, return the k most frequent elements within the array.
// The test cases are generated such that the answer is always unique.
// You may return the output in any order.

// Example 1:
// Input: nums = [1,2,2,3,3,3], k = 2
// Output: [2,3]

// Example 2:
// Input: nums = [7,7], k = 1
// Output: [7]

// Constraints:
// 1 <= nums.length <= 10^4.
// -1000 <= nums[i] <= 1000
// 1 <= k <= number of distinct elements in nums.

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> count;
        auto cmp =[](pair<int, int> a, pair<int, int> b)->bool{
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        for (int i : nums){
            count[i]++;
        }
        for (pair<int,int> i : count){
            que.push({i.second, i.first});
        }
        while (que.size() > k) {
            que.pop();
        }
        for (int i = 0; i < k; i++){
            result.push_back(que.top().second);
            que.pop();
        }
        return result;
    }
};
int main() {

}