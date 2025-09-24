#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

// https://neetcode.io/problems/car-fleet?list=neetcode150

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int result = 0;
        unordered_map<int, int> um;
        int n = position.size();
        for (int i = 0; i < n; i++){
            um[position[i]] = speed[i];
        }
        sort(position.begin(), position.end(), greater<int>());
        stack<int> st;
        for (auto pos : position){
            if (st.empty()){
                st.push(pos);
            }else{
                float time1 = ((float)target - (float)st.top())/(um[st.top()]);
                float time2 = ((float)target - (float)pos)/um[pos];
                // cout << "time1 " << time1 << "\n"
                //      << "time2 " << time2 << std::endl;
                if (time1<time2){
                    st.push(pos);
                }else{}
            }
        }
        result = st.size();
        return result;
    }
};


int main(){
    vector<int> input_pos = {4,1,0,7};
    vector<int> input_speed = {2,2,1,1};
    int target = 10;
    Solution s;
    s.carFleet(target, input_pos, input_speed);
    return 0;
}