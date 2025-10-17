#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>

// https://neetcode.io/problems/minimum-window-with-characters?list=neetcode150

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        unordered_map<char, int> um_temp;
        unordered_map<char, int> um_T;
        queue<int> pos;
        int min_length = INT_MAX;
        int result_l = 0, result_r = 0;
        for(char i: t){
            um_T[i]++;
        }
        for (int r = 0; r < s.size(); r++){
            if (um_T.find(s[r]) != um_T.end()){
                um_temp[s[r]]++;
                pos.push(r);
            }
            bool b_temp = true;
            for(pair<char, int> i: um_T){
                if(um_temp[s[i.first]] < i.second){
                    b_temp = false;
                    break;
                }
            }
            while (b_temp == true && um_T.find(s[l]) != um_T.end() && (um_temp[s[l]] - 1) >= 1){
                if (min_length < (r-l+1)){
                    min_length = r-l+1;
                    result_r = r;
                    result_l = l;
                    l = pos.front();
                    pos.pop();
                }
            }
            b_temp = false;
        }
        return s.substr(result_l,(result_r-result_l+1));
    }
};

int main() {

}