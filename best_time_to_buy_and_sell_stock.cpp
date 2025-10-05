#include <iostream>
#include <vector>
#include <algorithm>

// https://neetcode.io/problems/buy-and-sell-crypto?list=neetcode150

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxP = 0;

        while (r < prices.size()){
            if (prices[l] < prices[r]){
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit); 
            } else {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};


int main() {
    vector<int> input = {7,1,5,3,6,4};
    Solution s;
    s.maxProfit(input);
    return 1;
}