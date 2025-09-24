#include <iostream>
#include <vector>
#include <unordered_map>
// Contains Duplicate
// Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

// Example 1:
// Input: nums = [1, 2, 3, 3]
// Output: true

// Example 2:
// Input: nums = [1, 2, 3, 4]
// Output: false


class ContainsDuplicate {
    public:
    bool isContainsDuplicate(std::vector<int> input){
        bool result = false;
        std::unordered_map<int, int> map;
        if (input.size() == 0){
            return false;
        }
        for (auto i = input.begin(); i != input.end(); i++){
            if (map[*i] == 1){
                result = true;
                break;
            }
            map[*i] = 1;
        }
        return result;
    }
};

int main(){
    std::vector<int> input1 = {1,2,3,3,4};
    std::vector<int> input2 = {1,2,3,4,5};
    ContainsDuplicate test;

    std::cout << "vector1 is contain duplicate " << (test.isContainsDuplicate(input1) ? "True" : "False") << std::endl; 
    std::cout << "vector2 is contain duplicate " << (test.isContainsDuplicate(input2) ? "True" : "False") << std::endl; 
}