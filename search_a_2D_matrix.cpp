#include <iostream>
#include <vector>

// https://neetcode.io/problems/search-2d-matrix?list=neetcode150

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto v_temp : matrix){
            if (target < *v_temp.rbegin()){
                int l = 0;
                int r = v_temp.size();
                while (l <= r){
                    int mid = l+((r-l)/2);
                    if          (v_temp[mid] == target) return mid;
                    else if     (v_temp[mid] < target)  l = mid +1;
                    else                                r = mid - 1;
                }
                break;
            }
        }
        return -1;
    }
};


int main() {}