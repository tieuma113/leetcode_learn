#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

// https://neetcode.io/problems/time-based-key-value-store?list=neetcode150

using namespace std;

class TimeMap {
public:
    unordered_map<string, pair<vector<string>, vector<int>>> um_map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um_map[key].first.push_back(value);
        um_map[key].second.push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        vector<int> vec_temp;
        vec_temp = um_map[key].second;
        int result_timeStamp = -1;
        string result = "";
        int l = 0, m = 0, r = vec_temp.size() - 1;
        while (l <= r) {
            m = (l+r) / 2;
            if (vec_temp[m] == timestamp) {
                result_timeStamp = m;
                break;
            } 
            else if (vec_temp[m] < timestamp){
                result_timeStamp = m;
                l = m + 1;
            }else {
                r = m - 1;
            }
        }
        if (result_timeStamp != -1){
            result = um_map[key].first[result_timeStamp];
        }
        return result;
    }
};

int main() {

}