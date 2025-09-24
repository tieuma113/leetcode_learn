#include <iostream>
#include <vector>
#include <stack>


// Daily Temperatures
// You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.
// Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.

// Example 1:
// Input: temperatures = [30,38,30,36,35,40,28]
// Output: [1,4,1,2,1,0,0]

// Example 2:
// Input: temperatures = [22,21,20]
// Output: [0,0,0]

// Constraints:
// 1 <= temperatures.length <= 1000.
// 1 <= temperatures[i] <= 100


using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++){
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                result[st.top()]=(i-st.top());
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};

int main() {
    vector<int> input = {30,38,30,36,35,40,28};
    Solution s;
    s.dailyTemperatures(input);
    return 0;
}