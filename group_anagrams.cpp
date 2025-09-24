#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

//TODO: Group Anagrams

// Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

// Example 1:
// Input: strs = ["act","pots","tops","cat","stop","hat"]
// Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

// Example 2:
// Input: strs = ["x"]
// Output: [["x"]]

// Example 3:
// Input: strs = [""]
// Output: [[""]]

// Constraints:
// 1 <= strs.length <= 1000.
// 0 <= strs[i].length <= 100
// strs[i] is made up of lowercase English letters.
using namespace std;
class Groupnagrams {
    public:
    vector<vector<string>> groupnagrams(vector<string>& strs){
        vector<vector<string>> v_result;
        unordered_map<string, vector<string>> um_temp; 
        stringstream ss;
        for (auto str : strs) {
            vector<int> v_temp(26,0);
            ss.str("");
            ss.clear();
            for (auto s : str){
                v_temp[s-'a']++;
            }
            for (auto i : v_temp){
                ss << i << ",";
            }
            um_temp[ss.str()].push_back(str);
        }
        for (auto v_temp : um_temp){
            v_result.push_back(v_temp.second);
        }
        return v_result;
    }

};


int main() {
    vector<string> input = {"act","pots","tops","cat","stop","hat"};
    Groupnagrams test;
    test.groupnagrams(input);
    return 0;
}