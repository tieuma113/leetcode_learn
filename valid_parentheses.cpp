#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Valid Parentheses
// You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

// The input string s is valid if and only if:

// Every open bracket is closed by the same type of close bracket.
// Open brackets are closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Return true if s is a valid string, and false otherwise.

// Example 1:
// Input: s = "[]"
// Output: true

// Example 2:
// Input: s = "([{}])"
// Output: true

// Example 3:
// Input: s = "[(])"
// Output: false

// Explanation: The brackets are not closed in the correct order.

// Constraints:
// 1 <= s.length <= 1000


class Solution {
public:
    bool isValid(string s) {
        stack<char> st_stack;
        int result = true;
        char temp = ' ';
        for (auto i : s){
            switch (i) {
                case '{': 
                case '[':
                case '(':
                    st_stack.push(i);
                    break;
                case '}':
                    if (st_stack.empty()){
                        return false;
                    }
                    temp = st_stack.top();
                    if (temp != '{'){
                        result = false;
                        return result;
                    }else {
                        st_stack.pop();
                    }
                    break;
                case ']':
                    if (st_stack.empty()){
                        return false;
                    }
                    temp = st_stack.top();
                    if (temp != '['){
                        result = false;
                        return result;
                    }else {
                        st_stack.pop();
                    }
                    break;
                case ')':
                    if (st_stack.empty()){
                        return false;
                    }
                    temp = st_stack.top();
                    if (temp != '('){
                        result = false;
                        return result;
                    }else {
                        st_stack.pop();
                    }
                    break;
                default:
                    break;
            }
        }
        return result;
    }
};


int main(){

}