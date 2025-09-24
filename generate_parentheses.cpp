#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Generate Parentheses
// You are given an integer n. Return all well-formed parentheses strings that you can generate with n pairs of parentheses.

// Example 1:
// Input: n = 1
// Output: ["()"]

// Example 2:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// You may return the answer in any order.

// Constraints:
// 1 <= n <= 7


class Solution {
public:
    void backtrack(vector<string> &result, string current, int i_open, int i_close, int n){
        if (current.size() == 2*n){
            result.push_back(current);
            return;
        }
        if (i_open > i_close){
            string temp =  current + ")";
            result.push_back(temp);
            backtrack(result, temp, i_open, i_close+1, n);
        }
        if (i_open <= n){
            string temp = current + "(";
            result.push_back(temp);
            backtrack(result, temp, i_open + 1, i_close, n);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
        
    }
};



int main() {
    Solution s;
    s.generateParenthesis(3);
}