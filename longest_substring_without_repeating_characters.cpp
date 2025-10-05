#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

// https://neetcode.io/problems/longest-substring-without-duplicates?list=neetcode150

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int l = 0;
        set<char> temp;
        int max_length = 0;
        for (int r = 0; r < n; r++){
            while (temp.find(s[r]) != temp.end()){
                temp.erase(s[l]);
                l++;
            }
            temp.insert(s[r]);
            max_length = max(max_length, (r-l+1));
        }
        return max_length;
    }
};


int main() {

}