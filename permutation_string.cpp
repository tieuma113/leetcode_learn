#include <iostream>
#include <unordered_map>
#include <string>

// https://neetcode.io/problems/permutation-string?list=neetcode150

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> um_count;
        unordered_map<char, int> um_temp;
        for (auto i : s1){
            um_temp[i]++;
        }
        int n = s2.size();
        int size_s1 = s1.size();
        int l = 0;
        for (int r = 0; r < n; r++){
            um_count[s2[r]]++;
            if (r-l >= size_s1){
                um_count[s2[l]]--;
                l++;
            }
            bool result = true;
            for (auto i : um_temp){
                if (um_count.find(i.first) == nullptr || um_count[i.first] != i.second){
                    result = false;
                    break;
                }
            }
            if (result == true){
                return result;
            }
        }
        return false;
    }
};

int main(){
    string s1 = "ab";
    string s2 = "lecabee";
    Solution s;
    s.checkInclusion(s1, s2);
}