#include <iostream>
#include <string>
#include <unordered_map>

// Valid Anagram 
// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

// Example 1:
// Input: s = "racecar", t = "carrace"
// Output: true

// Example 2:
// Input: s = "jar", t = "jam"
// Output: false

// Constraints:2
// s and t consist of lowercase English letters.

class ValidAnagram{
    public:
    bool isValidAnagram(std::string s, std::string t){
        bool result = false;
        std::unordered_map<char, int> map;
        if (s.size() != t.size()){
            return false;
        }
        for (int i = 0; i < s.size(); i++){
            map[s[i]]++;
            map[t[i]]--;
        }
        result = true;
        for (auto i = map.begin(); i != map.end(); i++){
            if (i->second != 0){
                result = false;
                break;
            }
        }
        return result;
    }
};

int main(){
    std::string input1[] = {"racecar", "jar"};
    std::string input2[] = {"carrace", "jam"};
    ValidAnagram test;
    std::cout << "racecar and carrace is valid anagram " << (test.isValidAnagram(input1[0], input2[0]) ? "True" : "False") << std::endl;
    std::cout << "jar and jam is valid anagram " << (test.isValidAnagram(input1[1], input2[1]) ? "True" : "False") << std::endl;
}