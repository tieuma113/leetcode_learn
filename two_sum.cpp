#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

// Two Sum
// Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.
// You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
// Return the answer with the smaller index first.

// Example 1:
// Input: 
// nums = [3,4,5,6], target = 7
// Output: [0,1]
// Explanation: nums[0] + nums[1] == 7, so we return [0, 1].

// Example 2:
// Input: nums = [4,5,6], target = 10
// Output: [0,2]

// Example 3:
// Input: nums = [5,5], target = 10
// Output: [0,1]

// Constraints:
// 2 <= nums.length <= 1000
// -10,000,000 <= nums[i] <= 10,000,000
// -10,000,000 <= target <= 10,000,000
class TwoSum {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            if (map.find(target - nums[i]) != map.end()){
                result.push_back(map[target-nums[i]]);
                result.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }
        return result;
    }
};

int main(){
    std::pair<std::vector<int>, int> input[] = {{{3,4,5,6},    7},
                                                     {{4,5,6},      10},
                                                     {{5,5},        10}};
    TwoSum test;
    auto t = [&test](std::pair<std::vector<int>, int> input)-> std::string{
        std::stringstream result;
        std::vector<int> temp;
        temp = test.twoSum(input.first, input.second);

        for (auto i : temp){
            result << " " << i;
        }
        return result.str();
    };
    std::cout << "input 1 " << t(input[0]) << std::endl;
    std::cout << "input 2 " << t(input[1]) << std::endl; 
    std::cout << "input 3 " << t(input[2]) << std::endl; 
}