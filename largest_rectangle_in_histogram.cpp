#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

// https://neetcode.io/problems/largest-rectangle-in-histogram?list=neetcode150

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int result = 0;
    stack<pair<int, int>> st;
    int n = heights.size();
    int max = 0;
    for (int i = 0; i < n; i++) {
      pair<int, int> temp = make_pair(i, heights[i]);
      int pos = i;
      while (!st.empty() && temp.second < st.top().second) {
        int area = (temp.first - st.top().first) * st.top().second;
        if (max < area) {
          max = area;
        }
        pos = st.top().first;
        st.pop();
      }
      temp.first = pos;
      st.push(temp);
    }
    while (!st.empty()) {
      int area = (n - st.top().first) * st.top().second;
      if (max < area) {
        max = area;
      }
    }
    result = max;
    return result;
  }
};

int main() {
  vector<int> input = {7, 1, 7, 2, 2, 4};
  Solution s;
  s.largestRectangleArea(input);
  return 0;
}
