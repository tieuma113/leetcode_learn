#include <iostream>
#include <vector>
#include <cmath>

//	https://neetcode.io/problems/eating-bananas?list=neetcode150

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int result = 0;
        int l = 1;
        int r = 0;
        for (int p : piles){
            if (r < p) r = p;
        }
        while (l <= r) {
            int middle = l + (r-l)/2;
            int sum = 0;
            for (auto i : piles) {
                sum += ceil(static_cast<float>(i) / middle);
            }
            if (sum <= h) {
                result = middle;
                r = middle-1;
            }
            else l = middle + 1;
        }

        return result;
    }
};

int main() {
    vector<int> input = {1,1,1,999999999};

    Solution s;
    s.minEatingSpeed(input, 10);
}
