#include <iostream>
#include <vector>
#include <string>
#include <stack>


using namespace std;

class Solution {
public:
    bool isSign(string s){
        bool result = false;
        if (s == "+" || s == "-" || s == "*" || s == "/"){
            result = true;
        }
        return result;
    }

    bool isDigit(string s){
        bool result = true;
        if (s[0] == '-'){
            if (s.size() == 1){
                return false;
            }
            else{
                s[0] = '0';
            }
        }
        for (auto i : s){
            if (isdigit(i) == 0){
                result = false;
                break;
            }
        }
        return result;
    }



    int evalRPN(vector<string>& tokens) {
        int result;
        stack<int64_t> st_temp;
        for (auto i: tokens){
            if (isDigit(i)){
                st_temp.push(stoi(i));
            }else if(isSign(i)){
                int64_t temp_2 = st_temp.top();
                st_temp.pop();
                int64_t temp_1 = st_temp.top();
                st_temp.pop();
                int64_t temp_3 = 0;
                if (i == "+"){
                    temp_3 = temp_1 + temp_2;
                } else if (i == "-") {
                    temp_3 = temp_1 - temp_2;
                } else if (i == "*") {
                    temp_3 = temp_1 * temp_2;
                }else if(i == "/"){
                    temp_3 = temp_1 / temp_2;
                }
                st_temp.push(temp_3);
            }else {}
        }
        result = st_temp.top();
        return result;
    }
};


int main () {
    vector<string>  tokens={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution solution;
    cout << "result " << solution.evalRPN(tokens) << endl;
    return 0;
}