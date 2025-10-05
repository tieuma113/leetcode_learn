#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

// https://neetcode.io/problems/longest-repeating-substring-with-replacement?list=neetcode150

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int n = s.size();
        int result = 0;
        unordered_map<char, int> um_count;
        for (int r = 0; r < n; r++){
            um_count[s[r]]++;
            int maxf = 0;
            for (auto i : um_count){
                maxf = max(maxf, i.second);
            }
            while ((r-l+1 - maxf) > k){
                um_count[s[l]]--;
                l++;
                for (auto i : um_count){
                    maxf = max(maxf, i.second);
                }   
            }
            result = max(result, r-l+1);
        }
        return result;
    }
};

int main() {
    string input = "AAABABB";
    int k = 1;
    Solution s;
    s.characterReplacement(input, k);
}